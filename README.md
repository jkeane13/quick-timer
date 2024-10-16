![Quick Timer](./img/quick_timer.png)

Quick and easy timer with a duck quack alarm

## Features
- Starts a timer based on hours minutes and seconds, sequentially separated
  with spaces
- Start a timer by clock finish time (eg. 4:30)
- Start a timer by am/pm whole numbers (eg. 5pm)
- A script can be run instead of an alarm, if it's location is the last
  argument - Prompts for time with the `-p` switch
- Arguments can be "quick clock", am/pm, hours, minutes and seconds
- "Quick clock", is in a 12 hour cycle Eg: Running 9:30 after 9:30am will
  go to the next 12 hour block time of 9:30pm
- Has a `--quiet` switch to not make a noise at the end of the timer
  be able to play mp3 files

## Setup
### Prerequisites
- For Windows and Linux alerts to work, `mpg123` will need to be installed. Mac
will work fine, since `afplay` is default with the operating system

### Linux and Mac
Download the repo and run `make` to build the binary

### Installation
Running `make deploy` will copy the binary and assets into the `~/.local/bin`
directory. One will be created, if it doesn't exist. In order to run as a
local app, `~/.local/bin` will have to be added to your PATH

### Windows
Use a C compiler to build the binary with `make`

### Alert notication
In order to play the alert, the sound mp3 must be located in
`assets/duck_quack.mp3`

## Usage examples
For seconds, 15 seconds
```
timer 15
```

5 mins and 20 seconds
```
timer 5 20
```

1 hour 15 mins and 30 seconds
```
timer 1 15 30
```

For clock based time to go off at 6:00pm
```
timer 6pm
```

For clock based time to go off at the next 4:30
```
timer 4:30
```

Timer will run for 30 mins then execute a script
```
timer 30 0 "./assets/example.sh"
```

## End switches
`--quiet` : application will not set off an alarm
`--dry-run` : mainly for testing, timer instantly goes off in quiet mode

## Work in Progress
- Bug with quick clock: `timer 12:30` at 12:20pm comes back as 12:30am.
  Should be 12:30pm
