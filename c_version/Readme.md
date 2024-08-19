# C version of quick timer

## Current Features
- Prompts for time with the `-p` switch
- Arguments can be am/pm, hours, minutes and seconds and 24 hour
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
- Better argument reading in main
- Dry run mode `--dry-run`
- Windows deployer
- Better linux deployment
- Function testing framework
- Output testing framework
- Performance testing framework
- Accept 0:00 arguments
- Alternative alert to use beeps if sound file doesn't exit

### Bugs
- Go to the next 12:30 or 00:30 if it is past 12pm in the current time

### Clean up
- Rename alert to make noise for better clarity
- Player and filename parameter for alert for reuse
- Separate timer and alert in its own file for resuse
- Update usage
- Clean up output limitation error
