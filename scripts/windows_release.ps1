#Requires -Version 5.0
<#
.SYNOPSIS
    Builds and packages the quick-timer application for Windows.
.DESCRIPTION
    Compiles the timer using MINGW gcc, then packages the binary, assets, and config
    into a distributable zip file.
.EXAMPLE
    .\windows_release.ps1
.NOTES
    Requires MINGW gcc to be installed and available in PATH.
    Supports running from WSL via 'powershell' command.

    If you get execution policy errors, run from WSL with:
    powershell -ExecutionPolicy Bypass -File ./scripts/windows_release.ps1 -Clean
#>

param(
    [switch]$Clean = $false
)

$ErrorActionPreference = "Stop"

# Configuration
$ProgramName = "timer"
$SourceDir = "src"
$IncludeDir = "include"
$BuildDir = "build"
$AppName = "timer-windows"
$OutputZip = Join-Path $BuildDir "$AppName.zip"
$AssetsDir = "assets"
$ConfigDir = "config"

# Compiler settings
$CC = "gcc"
$CFLAGS = @(
    "-Werror"
    "-Wall"
    "-Wextra"
    "-std=c99"
    "-D_DEFAULT_SOURCE"
    "-O2"
)

# Libraries - pdcurses for Windows
$LDLIBS = "-lpdcurses"

# Platform detection - check if running from WSL
$IsWSL = $null -ne (Get-Command wsl.exe -ErrorAction SilentlyContinue)

Write-Host "Quick Timer - Windows Release Build" -ForegroundColor Cyan
Write-Host "===================================" -ForegroundColor Cyan
Write-Host ""

# Clean if requested
if ($Clean) {
    Write-Host "Cleaning build directory..." -ForegroundColor Yellow
    if (Test-Path $BuildDir) {
        Remove-Item $BuildDir -Recurse -Force
    }
    if (Test-Path $AppName) {
        Remove-Item $AppName -Recurse -Force
    }
    if (Test-Path $OutputZip) {
        Remove-Item $OutputZip -Force
    }
    Write-Host "Clean complete." -ForegroundColor Green
}

# Verify source files exist
$Sources = @(Get-ChildItem -Path $SourceDir -Filter "*.c" -ErrorAction SilentlyContinue).FullName
if ($Sources.Count -eq 0) {
    Write-Error "No source files found in $SourceDir"
}

Write-Host "Found $($Sources.Count) source files" -ForegroundColor Green

# Create build directory
New-Item -ItemType Directory -Path $BuildDir -Force | Out-Null

# Compile each source file to object files
Write-Host "Compiling source files..." -ForegroundColor Yellow
$ObjectFiles = @()

foreach ($SourceFile in $Sources) {
    $BaseName = (Get-Item $SourceFile).BaseName
    $ObjectFile = Join-Path $BuildDir "$BaseName.o"

    $CompileCmd = "$CC $($CFLAGS -join ' ') -I$IncludeDir -c `"$SourceFile`" -o `"$ObjectFile`""

    Write-Host "  Compiling $BaseName..."
    Invoke-Expression $CompileCmd

    if ($LASTEXITCODE -ne 0) {
        Write-Error "Compilation failed for $SourceFile"
    }

    $ObjectFiles += $ObjectFile
}

Write-Host "Compilation complete." -ForegroundColor Green

# Link object files into executable
Write-Host "Linking executable..." -ForegroundColor Yellow
$Binary = Join-Path $BuildDir "$ProgramName.exe"
$LinkCmd = "$CC $($ObjectFiles -join ' ') $LDLIBS -o `"$Binary`""

Invoke-Expression $LinkCmd

if ($LASTEXITCODE -ne 0) {
    Write-Error "Linking failed"
}

Write-Host "Binary created: $Binary" -ForegroundColor Green

# Create release directory structure
Write-Host "Creating release package..." -ForegroundColor Yellow
New-Item -ItemType Directory -Path "$AppName\bin" -Force | Out-Null
New-Item -ItemType Directory -Path "$AppName\assets" -Force | Out-Null
New-Item -ItemType Directory -Path "$AppName\config" -Force | Out-Null

# Copy files
Write-Host "  Copying binary..."
Copy-Item -Path $Binary -Destination "$AppName\bin\"

Write-Host "  Copying assets..."
if (Test-Path $AssetsDir) {
    Get-ChildItem -Path $AssetsDir -Filter "*.mp3" | ForEach-Object {
        Copy-Item -Path $_.FullName -Destination "$AppName\assets\"
    }
}

Write-Host "  Copying config..."
if (Test-Path $ConfigDir) {
    Get-ChildItem -Path $ConfigDir -Filter "*.cfg" | ForEach-Object {
        Copy-Item -Path $_.FullName -Destination "$AppName\config\"
    }
}

# Create zip file
Write-Host "Creating zip archive..." -ForegroundColor Yellow
Compress-Archive -Path $AppName -DestinationPath $OutputZip -Force

if ($LASTEXITCODE -ne 0) {
    Write-Error "Failed to create zip archive"
}

Write-Host "Archive created: $OutputZip" -ForegroundColor Green

# Cleanup
Write-Host "Cleaning up temporary files..." -ForegroundColor Yellow
Remove-Item $AppName -Recurse -Force

Write-Host ""
Write-Host "Build successful!" -ForegroundColor Green
Write-Host "Release package: $OutputZip" -ForegroundColor Cyan
