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
- `timer 50 0` seems to be not reading the last parameter and setting to 50
  seconds when using the `-p` switch
- Timer goes off if hour is set to the same hour, even with a minute change Eg
  8:34 won't work if it is 8:28
- "am" and "pm" inputs will not work with there is a space between the time and
  suffix (eg "12 pm, instead of 12pm")
- Test Clock time to make sure it ends at the correct time

### Features
- Bump the time up to 12 hours in am or pm is not specified.
  (Eg 1:30 timer at 3:30pm will go off at 1:30am)
- Able to open a file at the end of a timer, via a switch
- Alternative alert to use beeps if sound file doesn't exist
- Convert alert function and file to a sound player with windows location
  converter

### Quality of Life
- Test every function in some way...
- Subdivide timer function to smaller files for reuse and easier reading
- Subdivide timer test to smaller files for reuse and easier reading
- Convert alert function to be a cross platform sound player for reuse
- Update test framework to be grouped up
