# C version of quick timer

## Current Features
- Prompts for seconds, then sounds out an alarm when the timer is done
- Alerts will work for Mac and Linux. However Linux will need to have `mpg123`
  installed to be able to play mp3 files

## Future planned features
- Alarm Noise for Windows
- Timer argument based on hours minutes and seconds, sequentially separated
  with spaces
- Start a timer by clock finish time (eg. 4:30)
- Start a timer by am/pm whole numbers (eg. 5pm)
- Prompt with -p switch
- Silent countdown
- Quiet switch --quiet
- Dry run mode
- Windows compatibility. Only Mac terminal for now

## Installation
Download the repo and run make to build the binary
