# C version of quick timer

## Current Features
- Prompts for seconds and can accept argument in the format of hours, minutes
  and seconds. Then sounds out an alarm when the timer is done
- For alerts for Windows and Linux to work, you will need to have `mpg123`
  installed to be able to play mp3 files

## Future planned features
- Start a timer by clock finish time (eg. 4:30)
- Start a timer by am/pm whole numbers (eg. 5pm)
- Silent countdown
- Quiet switch --quiet
- Dry run mode
- Windows deployer of the application
- Better Linux deployment

## Installation
### Linux and Mac
Download the repo and run `make` to build the binary

### Windows
Use a gcc compiler to build the binary

### Alert notication
In order to play the alert, the sound mp3 must be located in
`assets\duck_quack.mp3`

