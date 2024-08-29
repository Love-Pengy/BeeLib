#include "timeElapsed.h"
#include <stdio.h>
#include <unistd.h>
int main(void) {
  // NOTE: with no optimization the timers starting and stopping takes 1 us
  bench *tester = startTimer();
  sleep(1);
  endTimer(tester);
  getElapsedTimeUs_print(tester);
  getElapsedTimeNs_print(tester);
  freeTimer(&tester);
}
