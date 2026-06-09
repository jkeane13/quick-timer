@echo off
setlocal enabledelayedexpansion

REM Create release directory structure
if not exist timer-windows\bin mkdir timer-windows\bin
if not exist timer-windows\assets mkdir timer-windows\assets
if not exist timer-windows\config mkdir timer-windows\config

REM Copy binary and assets
copy timer.exe timer-windows\bin\
copy assets\*.mp3 timer-windows\assets\
copy config\*.cfg timer-windows\config\

REM Create zip file
powershell -Command "Compress-Archive -Path timer-windows -DestinationPath timer-windows.zip -Force"

REM Cleanup
rmdir /s /q timer-windows

endlocal
