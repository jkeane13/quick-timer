@ECHO OFF

ECHO Create Timer folder...
MKDIR "C:\Program Files\Quick Timer"

ECHO Create .local folder in home folder...
MKDIR %homepath%\.local

ECHO Create assets folder in .local folder...
MKDIR %homepath%\.local\assets

ECHO Copying Timer...
COPY ..\build\timer.exe "C:\Program Files\Quick Timer\"

ECHO Copying Timer Alert...
COPY ..\assets\stopwatch.mp3 %homepath%\.local\assets\

IF NOT EXIST "C:\Program Files\Quick Timer\mpg123.exe" (
    ECHO "Alarm mpg123.exe needs to be put in this directory, for the alarm to work."
)

