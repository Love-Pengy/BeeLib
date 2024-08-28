#include "timeElapsed.h"
#include <stdio.h>
#include <unistd.h>
int main(void) {
  // NOTE: with no optimization the timers starting and stopping takes 1 us
  bench *tester = startTimer();
  sleep(1);
  endTimer(tester);
  long micro = getElapsedTimeUs(tester);
  long nano = getElapsedTimeNs(tester);
  printf("%ld | %ld\n", micro, nano); 
  freeTimer(&tester);
}
