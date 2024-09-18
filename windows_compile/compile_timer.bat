@echo off

echo Compiling...
cd ..
gcc ^
src\args_checker_handler.c ^
src\args_prompt_handler.c ^
src\args_switch_handler.c ^
src\convert_12_hour_clock_to_24.c ^
src\convert_24_clock_to_12.c ^
src\convert_24_clock_to_seconds.c ^
src\convert_args_to_seconds.c ^
src\convert_quick_clock_to_24.c ^
src\countdown_seconds.c ^
src\edit_characters.c ^
src\get_hour_and_minutes.c ^
src\main.c ^
src\play_audio.c ^
src\print_clock.c ^
src\run_application.c ^
src\usage.c ^
-o ^
build\timer.exe
echo Done!
pause
