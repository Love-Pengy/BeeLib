#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include "timeElapsed.h"
int main(void) {
  char fName1[20] = "~/Projects/git-stats";
  char fName2[25] = "~/Projects/study-tracker/";
  bench* timer = startTimer();
  struct stat attr1, attr2;
  stat(fName1, &attr1);
  errno = 0;
  struct tm *val1 = localtime(&attr1.st_mtim.tv_sec);
  if (errno) {
    perror("getModifiedTime");
  }
  time_t time1 = mktime(val1);

  errno = 0;
  stat(fName2, &attr2);
  if(errno){
    perror("");
  }
  errno = 0;
  struct tm *val2 = localtime(&attr2.st_mtim.tv_sec);
  if (errno) {
    perror("getModifiedTime");
  }
  time_t time2 = mktime(val2);
  endTimer(timer);
  getElapsedTimeNs_print(timer);
  freeTimer(&timer);
  printf("MOD TIME DIFF: %lf seconds\n", difftime(time1, time2));
  
  return (0);
}
