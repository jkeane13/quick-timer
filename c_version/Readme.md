# C version of quick timer

## Current Features
- Prompts for seconds
- Arguments can accept formated of hours, minutes in 24 hours or am/pm
  and seconds. Then sounds out an alarm when the timer is done
- For alerts for Windows and Linux to work, you will need to have `mpg123`
  installed to be able to play mp3 files

## Future planned features
- Quiet switch (--quiet)
- Dry run mode
- Windows deployer of the application
- Better Linux deployment
- Fix bug with adding time in the same hour (eg 5pm in the hour of 5 will be instant)
- Testing different times (after quiet and dry run mode installed)

## Installation
### Linux and Mac
Download the repo and run `make` to build the binary

### Windows
Use a gcc compiler to build the binary

### Alert notication
In order to play the alert, the sound mp3 must be located in
`assets/duck_quack.mp3`

