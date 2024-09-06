# C version of quick timer

## Current Features
- Prompts for time with the `-p` switch
- Arguments can be am/pm, hours, minutes and seconds
- Can do a "quick clock", Eg: Running 9:30 after 10am will go to the next 12
  hour block time of 9:30pm
- Has a `--quiet` switch to not make a noise at the end of the timer
- For Windows and Linux alerts to work, `mpg123` will need to be installed to
  be able to play mp3 files

## Installation
### Linux and Mac
Download the repo and run `make` to build the binary

### Windows
Use a C compiler to build the binary

### Alert notication
In order to play the alert, the sound mp3 must be located in
`assets/duck_quack.mp3`

##  Todo list
- 256 character limit on exectable argument, before the application will break
- Add failsafe system beeps if sound file or player application doesn't exist
- Countdown Seconds Tests
- Review Main Output Tests
- Print Clock Tests
- Run Application Tests
- Usage Tests
- Add a meow alert
- Optimise `duck_quack.mp3`
- Add consistancy of alerts, by adding a periodic time (eg 0.5 or 1 second)
- Clean up `run_application.c` to utilise sprintf for cleaner code

### After tests
- Replace bash primary folder with C version
- Integrate tests with GitHub Actions
