#Requires -Version 5.0
<#
.SYNOPSIS
    Builds and packages the quick-timer application for Windows.
.DESCRIPTION
    Compiles the timer using MINGW gcc, then packages the binary into a
    distributable zip file.
.EXAMPLE
    .\windows_release.ps1
    .\windows_release.ps1 -Clean
.NOTES
    Requires MINGW gcc to be installed and available in PATH.
    Supports running from WSL via 'powershell' command.

    If you get execution policy errors, run from WSL with:
    powershell -ExecutionPolicy Bypass -File ./scripts/windows_release.ps1 -Clean
#>

param(
    [switch]$CLEAN_BUILD = $false
)

$ErrorActionPreference = "Stop"

# Global Configuration
$PROGRAM_NAME = "timer"
$SOURCE_DIR = "src"
$INCLUDE_DIR = "include"
$BUILD_DIR = "build"
$APP_NAME = "timer-windows"
$OUTPUT_ZIP = Join-Path $BUILD_DIR "$APP_NAME.zip"
$CC = "gcc"
$CFLAGS = @("-Werror", "-Wall", "-Wextra", "-std=c99", "-D_DEFAULT_SOURCE", "-O2")
$LDLIBS = "-lpdcurses"

$OBJECT_FILES = @()

function Main-TimerBuild {
    Write-Header

    if ($CLEAN_BUILD) {
        CleanBuild
    }

    GenerateHeaders
    VerifySourceFiles
    CompileSourceFiles
    LinkExecutable
    CreateReleasePackage
    CreateZipArchive
    CleanupTemporaryFiles

    Write-Success
}

function Write-Header {
    Write-Host "Quick Timer - Windows Release Build" -ForegroundColor Cyan
    Write-Host "===================================" -ForegroundColor Cyan
    Write-Host ""
}

function CleanBuild {
    Write-Host "Cleaning build directory..." -ForegroundColor Yellow

    if (Test-Path $BUILD_DIR) {
        Remove-Item $BUILD_DIR -Recurse -Force
    }
    if (Test-Path $APP_NAME) {
        Remove-Item $APP_NAME -Recurse -Force
    }
    if (Test-Path $OUTPUT_ZIP) {
        Remove-Item $OUTPUT_ZIP -Force
    }

    Write-Host "Clean complete." -ForegroundColor Green
    Write-Host ""
}

function GenerateHeaders {
    Write-Host "Generating headers..." -ForegroundColor Yellow

    $AUDIO_HEADER = Join-Path $INCLUDE_DIR "stopwatch_audio.h"
    $AUDIO_FILE = "assets/stopwatch.mp3"

    if (Test-Path $AUDIO_FILE) {
        New-Item -ItemType Directory -Path $INCLUDE_DIR -Force | Out-Null

        $bytes = [System.IO.File]::ReadAllBytes($AUDIO_FILE)
        $varName = ([System.IO.Path]::GetFileName($AUDIO_FILE) -replace '[^a-zA-Z0-9_]', '_')

        $header = @("unsigned char $varName`[] = {")
        $line = ""

        for ($i = 0; $i -lt $bytes.Length; $i++) {
            $line += "0x$($bytes[$i].ToString('x2'))"

            if ($i -lt $bytes.Length - 1) {
                $line += ", "
            }

            if (($i + 1) % 12 -eq 0 -or $i -eq $bytes.Length - 1) {
                $header += "  $line"
                $line = ""
            }
        }

        $header += "};`nunsigned int $varName`_len = $($bytes.Length);"

        [System.IO.File]::WriteAllText($AUDIO_HEADER, ($header -join "`n"))
        Write-Host "Generated: $AUDIO_HEADER" -ForegroundColor Green
    } else {
        Write-Error "Audio file not found: $AUDIO_FILE"
    }

    Write-Host ""
}

function VerifySourceFiles {
    $global:SOURCE_FILES = @(Get-ChildItem -Path $SOURCE_DIR -Filter "*.c" -ErrorAction SilentlyContinue).FullName

    if ($SOURCE_FILES.Count -eq 0) {
        Write-Error "No source files found in $SOURCE_DIR"
    }

    Write-Host "Found $($SOURCE_FILES.Count) source files" -ForegroundColor Green
    New-Item -ItemType Directory -Path $BUILD_DIR -Force | Out-Null
}

function CompileSourceFiles {
    Write-Host "Compiling source files..." -ForegroundColor Yellow

    foreach ($SOURCE_FILE in $SOURCE_FILES) {
        $BASE_NAME = (Get-Item $SOURCE_FILE).BaseName
        $OBJECT_FILE = Join-Path $BUILD_DIR "$BASE_NAME.o"

        $COMPILE_CMD = "$CC $($CFLAGS -join ' ') -I$INCLUDE_DIR -c `"$SOURCE_FILE`" -o `"$OBJECT_FILE`""

        Write-Host "  Compiling $BASE_NAME..."
        Invoke-Expression $COMPILE_CMD

        if ($LASTEXITCODE -ne 0) {
            Write-Error "Compilation failed for $SOURCE_FILE"
        }

        $global:OBJECT_FILES += $OBJECT_FILE
    }

    Write-Host "Compilation complete." -ForegroundColor Green
}

function LinkExecutable {
    Write-Host "Linking executable..." -ForegroundColor Yellow

    $BINARY = Join-Path $BUILD_DIR "$PROGRAM_NAME.exe"
    $LINK_CMD = "$CC $($OBJECT_FILES -join ' ') $LDLIBS -o `"$BINARY`""

    Write-Host "Link command: $LINK_CMD" -ForegroundColor Gray
    $OUTPUT = Invoke-Expression $LINK_CMD 2>&1

    if ($LASTEXITCODE -ne 0) {
        Write-Host "Linker output: $OUTPUT" -ForegroundColor Red
        Write-Error "Linking failed"
    }

    Write-Host "Binary created: $BINARY" -ForegroundColor Green
}

function CreateReleasePackage {
    Write-Host "Creating release package..." -ForegroundColor Yellow

    New-Item -ItemType Directory -Path "$APP_NAME\bin" -Force | Out-Null

    $BINARY = Join-Path $BUILD_DIR "$PROGRAM_NAME.exe"

    Write-Host "  Copying binary..."
    Copy-Item -Path $BINARY -Destination "$APP_NAME\bin\"
}

function CreateZipArchive {
    Write-Host "Creating zip archive..." -ForegroundColor Yellow
    Compress-Archive -Path $APP_NAME -DestinationPath $OUTPUT_ZIP -Force

    if ($LASTEXITCODE -ne 0) {
        Write-Error "Failed to create zip archive"
    }

    Write-Host "Archive created: $OUTPUT_ZIP" -ForegroundColor Green
}

function CleanupTemporaryFiles {
    Write-Host "Cleaning up temporary files..." -ForegroundColor Yellow
    Remove-Item $APP_NAME -Recurse -Force
}

function Write-Success {
    Write-Host ""
    Write-Host "Build successful!" -ForegroundColor Green
    Write-Host "Release package: $OUTPUT_ZIP" -ForegroundColor Cyan
}

Main-TimerBuild
