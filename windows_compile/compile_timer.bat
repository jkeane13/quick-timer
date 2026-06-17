@echo off

echo Compiling...
cd ..
gcc src\*.c -o build\timer.exe -lpdcurses
cd windows_compile
echo Done!

