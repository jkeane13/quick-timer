# Bash Version

## Setup
### gdate requirement for Mac OS
For this to work on Mac OS you will need gdate. The Mac OS date command's
switches are different to that of Linux. gdate is part of the
coreutils package and can be installed using Homebrew by running the following
```
brew install coreutils
```

### Installation

Clone this repo to your desktop or download the `timer.sh` script

You might want add an alias in your `.bashrc` or `.zshrc` file for quick
access. (eg `alias timer=~/timer.sh`)

## Usage examples
For seconds, 15 seconds
```
timer.sh 15
```

5 mins and 20 seconds
```
timer.sh 5 20
```

1 hour 15 mins and 30 seconds
```
timer.sh 1 15 30
```

For clock based time to go off at 6:00pm
```
timer.sh 6pm
```

For clock based time to go off at the next 4:30
```
timer.sh 4:30
```

Timer will run for 30 mins then execute a script
```
timer.sh 30 0 "./test.sh"
```
