@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

ECHO =========================
ECHO     COMPILING TIMER
ECHO =========================

REM Find the repo root (go up from .local\bin if running from there)
IF EXIST "src\main.c" (
    SET REPO_ROOT=%CD%
) ELSE (
    REM Assume repo is one level up from this script's directory
    cd ..
    IF EXIST "src\main.c" (
        SET REPO_ROOT=%CD%
    ) ELSE (
        ECHO Error: Could not find quick-timer source files
        ECHO Run this script from the quick-timer repo root directory
        pause
        EXIT /B 1
    )
)

cd /d "%REPO_ROOT%"

REM Create build directory if it doesn't exist
IF NOT EXIST "build" MKDIR build

REM Compile all source files
SET "SOURCES="
FOR %%F IN (src\*.c) DO SET "SOURCES=!SOURCES! %%F"

gcc %SOURCES% -o build/timer.exe -lpdcurses -mconsole

IF %ERRORLEVEL% NEQ 0 (
    ECHO Compilation failed!
    pause
    EXIT /B 1
)

ECHO =========================
ECHO     DEPLOYING TIMER
ECHO =========================

IF NOT EXIST "%HOMEDRIVE%%HOMEPATH%\.local\bin" (
    ECHO Creating .local\bin folder...
    MKDIR "%HOMEDRIVE%%HOMEPATH%\.local\bin"
)

IF NOT EXIST "%HOMEDRIVE%%HOMEPATH%\.local\assets" (
    ECHO Creating .local\assets folder...
    MKDIR "%HOMEDRIVE%%HOMEPATH%\.local\assets"
)

IF NOT EXIST "%HOMEDRIVE%%HOMEPATH%\.local\config" (
    ECHO Creating .local\config folder...
    MKDIR "%HOMEDRIVE%%HOMEPATH%\.local\config"
)

ECHO Copying Timer executable...
COPY "%REPO_ROOT%\build\timer.exe" "%HOMEDRIVE%%HOMEPATH%\.local\bin\"

ECHO Copying audio assets...
COPY "%REPO_ROOT%\assets\stopwatch.mp3" "%HOMEDRIVE%%HOMEPATH%\.local\assets\"

ECHO Copying configuration...
COPY "%REPO_ROOT%\config\timer.cfg" "%HOMEDRIVE%%HOMEPATH%\.local\config\"

ECHO =========================
ECHO     DEPLOYMENT COMPLETE
ECHO =========================
ECHO Timer installed to: %HOMEDRIVE%%HOMEPATH%\.local\bin\timer.exe
pause

