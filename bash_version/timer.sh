#!/bin/bash

number_of_beeps=5
os=$(uname -s)

function usage {
    echo "usage:

    Countdown to the second, minute or hour. Will also run a script, instead of
    an alarm, if it is the last argument

    timer [seconds]
    timer [minutes] [seconds]
    timer [hours] [minutes] [seconds]
    timer [hours] [minutes] [seconds] [script]
    timer [clock]
    timer [clock] [script]

    EXAMPLE: 2 hours, 10 minutes, 1 second
    timer 2 10 1

    Countdown to a specific time
    timer [hour:minute]

    EXAMPLE: Timer for 5:30 am or pm
    timer 5:30

    EXAMPLE: Timer will run for 30 mins then execute a script. This is
    recognised by the .sh extension
    timer 30 0 example.sh

    End switches
    --quiet : application will not set off an alarm

    --dry-run : mainly for testing to determine if the end time is correct
    "
    exit 1
}

function check_os_date_command(){
    date_cmd="date"
    if [ "$os" == "Darwin" ]; then
        date_cmd="gdate"
    fi
}

function countdown(){
    case "$#" in
        3)
        countdown_time=$(( $1 * 3600 + $2 * 60 + $3 ))
        ;;
        2)
        countdown_time=$(( $1 * 60 + $2 ))
        ;;
        1)
        countdown_time=$1
        ;;
    esac

    if [[ $countdown_time == *"pm" || $countdown_time == *"am" ]]; then
        countdown_time_suffix=${countdown_time: -2}
        countdown_time=${countdown_time::${#countdown_time}-2}
        if [[ ${#countdown_time}  -lt 3 ]];then
            countdown_time=${countdown_time}":00"
        fi
    fi

    if [[ $countdown_time == *":"* ]]; then
        today_date=$(date +"%b %d %Y")
        end=$($date_cmd -d "$today_date $countdown_time:00" +%s)
        now=$($date_cmd +%s)
        while [ "$now" -gt "$end" ] ; do
            end=$(( end + $(( 12*60*60)) ))
        done
        countdown_time=$(( (end-now) ))
    fi

    endtime_suffix=$($date_cmd -d +${countdown_time}seconds +'%P' )
    if [[ "$countdown_time_suffix" !=  "$endtime_suffix" && "$countdown_time_suffix" != "" ]];then
        countdown_time=$(( countdown_time + $((12*60*60)) ))
    fi

    endtime=$($date_cmd -d +${countdown_time}seconds +'%l:%M %P')
    echo Timer ends at "$(echo "$endtime"| xargs)"

    if ! [[ $dry_run == "true" ]];then
        date_new=$(($($date_cmd +%s) + countdown_time));
        while [ "$date_new" -ge "$(date +%s)" ]; do
            echo -ne "$($date_cmd -u --date @$((date_new - $($date_cmd +%s))) +%H:%M:%S)\r";
            sleep 0.25
        done

        echo Timer Done!
    fi
}

function alarm_ring(){
    for _ in $(seq $number_of_beeps); do
        if [ "$os" == "Darwin" ]; then
            say beep
        else
            # Windows WSL will need to call PowerShell to make a noise
            /mnt/c/Windows/System32/WindowsPowerShell/v1.0/powershell.exe '[console]::beep(261.6,700)'
        fi
    done
}

function check_script(){
    if [[ ${!#} == *".sh" ]];then
        timer_script=${!#}
        strip_last_parameter "$@"
    else
        timer_clock=$*
    fi
    if [ ! -f "$timer_script" ] && [ -n "$timer_script" ]; then
        echo "ERROR: $timer_script does not exist"
        exit 1
    fi

}

function strip_last_parameter(){
    timer_clock=$(echo "$@" | awk '{$NF="";sub(/[ \t]+$/,"")}1')
}


# main
[ -z "$1" ] && { usage; }
check_os_date_command

case ${!#} in
    *".sh")
    check_script "$@"
    countdown $timer_clock
    ;;

    "--quiet")
    strip_last_parameter "$@"
    countdown $timer_clock
    exit 0
    ;;
    "--dry-run")
    dry_run=true
    strip_last_parameter "$@"
    countdown $timer_clock
    exit 0
    ;;
    esac

countdown "$@"
if [[ $timer_script == "" ]]; then
    alarm_ring
else
    echo Running script "$timer_script"...
    $timer_script
fi

