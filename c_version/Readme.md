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

## Todo List
### Future planned features
- Play 12 hour time for Timer ends output
- Windows deployer
- Better linux deployment
- Performance testing framework
- Alternative alert to use beeps if sound file doesn't exist

## Buggy Input Times to Fix
- Any hour digit in the same hour. Eg - 8:34 won't work if it is 8:28
- 12am and 12pm inputs
- `printf("")` warnings with Windows gcc compiler in timer test
