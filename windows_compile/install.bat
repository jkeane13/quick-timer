@ECHO OFF

IF NOT EXIST "C:\Program Files\Quick Timer\" (
    ECHO Creating Timer folder...
    MKDIR "C:\Program Files\Quick Timer"
)

IF NOT EXIST %homedrive%%homepath%\.local (
    ECHO Creating .local folder in home folder...
    MKDIR %homepath%\.local
)

IF NOT EXIST %homedrive%%homepath%\.local\assets (
    ECHO Create assets folder in .local folder...
    MKDIR %homepath%\.local\assets
)

IF NOT EXIST %homedrive%%homepath%\.local\config (
    ECHO Create configuration folder in .config...
    MKDIR %homedrive%%homepath%\.local\config
)

ECHO Copying Timer...
COPY ..\build\timer.exe "C:\Program Files\Quick Timer\"

ECHO Copying Timer Alert...
COPY ..\assets\stopwatch.mp3 %homedrive%%homepath%\.local\assets\

ECHO Copy Configuration...
COPY ..\config\timer.cfg %homedrive%%homepath%\.local\config\

IF NOT EXIST "C:\Program Files\Quick Timer\mpg123.exe" (
    ECHO "Alarm mpg123.exe needs to be put in this directory, for the alarm to work."
)
