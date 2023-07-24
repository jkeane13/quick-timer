setup() {
    load 'test_helper/bats-support/load'
    load 'test_helper/bats-assert/load'
    os=$(uname -s)

    function check_os_date_command(){
        date_cmd="date"
        if [ "$os" == "Darwin" ]; then
            date_cmd="gdate"
        fi
    }
}

@test "Helper comes up when no parameters are given" {
    run ./timer.sh
    assert_output --partial 'Countdown to the second'
    [ "$status" -eq 1 ]
}

@test "Timer will do a countdown" {
    run ./timer.sh 1 --quiet
    assert_output --partial 'Timer Done!'
}

@test "Timer will do a minute countdown" {
    run ./timer.sh 1 0 --dry-run
    check_os_date_command
    end_time=$($date_cmd -d "+1 minute" +'%l:%M %P' | xargs)
    assert_output "Timer ends at ${end_time}"
}

@test "Timer will do a hour countdown" {
    run ./timer.sh 1 0 0 --dry-run
    check_os_date_command
    end_time=$($date_cmd -d "+1 hour" +'%l:%M %P' | xargs)
    assert_output "Timer ends at ${end_time}"
}

@test "Timer able to do 12-24 hours with am and pm" {
    check_os_date_command
    run ./timer.sh $(date_cmd +%l%P) --dry-run
    end_time=$($date_cmd +'%l:%M %P' | xargs)
    assert_output "Timer ends at ${end_time}"
}

@test "Timer script runs at the end of timer" {
    run ./timer.sh 1 ./example.sh
    assert_output --partial 'Hello World!'
}

@test "Error comes up if a script file doesn't exist" {
    run ./timer.sh 1 no_bash_file.sh
    assert_output  'ERROR: no_bash_file.sh does not exist'
    [ "$status" -eq 1 ]
}

