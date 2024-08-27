# C version of quick timer

## Current Features
- Prompts for time with the `-p` switch
- Arguments can be am/pm, hours, minutes and seconds and 24 hour
- Has a `--quiet` switch to not make a noise at the end of the timer
- For alerts for Windows and Linux to work, you will need to have `mpg123`
  installed to be able to play mp3 files

## Installation
### Linux and Mac
Download the repo and run `make` to build the binary

### Windows
Use a C compiler to build the binary

### Alert notication
In order to play the alert, the sound mp3 must be located in
`assets/duck_quack.mp3`

##  Todo list
Criticality is based on priority
### Bugs
- Timer goes off if hour is set to the same hour, even with a minute change Eg
  8:34 won't work if it is 8:28
- Set executable arg to use malloc, due to random input

### Features
- Bump the time up to 12 hours in am or pm is not specified.
  (Eg 1:30 timer at 3:30pm will go off at 1:30am)
- Alternative alert to use beeps if sound file doesn't exist
- Convert alert function and file to a sound player with windows location
  converter

### Quality of Life
- Convert alert function to be a cross platform sound player for reuse
