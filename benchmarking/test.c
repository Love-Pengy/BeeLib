#include "timeElapsed.h"
#include <stdio.h>
#include <unistd.h>
int main (void){
    //NOTE: with no optimization the timers starting and stopping takes 1 us
    bench* tester = startTimer();
    sleep(1);
    endTimer(tester);
    printf("%ld\n", getElapsedTime(tester));
    freeTimer(&tester); 
    endTimer(tester);
    printf("%ld\n", getElapsedTime(tester));
}
