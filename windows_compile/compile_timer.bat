@echo off

echo Compiling...
cd ..
gcc src\*.c -o build\timer.exe
cd windows_compile
echo Done!

