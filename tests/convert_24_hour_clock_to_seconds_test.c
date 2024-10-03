#include "../include/timer.h"
#include "../include/testing.h"

void convert321HoursMinsToSeconds(){
    statement("Convert 3 Hours, 2 mins and 1 second to seconds");
    assertInt(10921, convertHoursMinsToSeconds(3,2,1));
}

int main(int argc, char **argv) {
    testTitle("Testing 24 hour clock to seconds functions",__FILE__);
    convert321HoursMinsToSeconds();

    return 0;
}

