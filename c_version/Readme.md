# C version of quick timer

## Current Features
- Prompts for time with the `-p` switch
- Arguments can be "quick clock", am/pm, hours, minutes and seconds
- "Quick clock", is in a 12 hour cycle Eg: Running 9:30 after 9:30am will
  go to the next 12 hour block time of 9:30pm
- Has a `--quiet` switch to not make a noise at the end of the timer
- For Windows and Linux alerts to work, `mpg123` will need to be installed to
  be able to play mp3 files

## Installation
### Linux and Mac
Download the repo and run `make` to build the binary

Running `make deploy` will copy the binary and assets into the `~/.local/bin`
directory

### Windows
Use a C compiler to build the binary

### Alert notication
In order to play the alert, the sound mp3 must be located in
`assets/duck_quack.mp3`

##  Todo list
- Replace bash primary folder with C version
- Integrate tests with GitHub Actions
