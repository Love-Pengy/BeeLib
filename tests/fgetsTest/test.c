#include "timeElapsed.h"
#include <stdio.h>
#include <string.h>
int main(void) {
  printf("THIS IS FGETS\n");
  printf("-----------------------\n");
  char output[1000];
  char command[62] =
      "/usr/bin/git -C /home/bee/Projects/git-stats/ diff --shortstat";
  FILE *fp = popen(command, "r");
  bench *timer = startTimer();
  char *terminalOutput = fgets(output, sizeof(output), fp);
  endTimer(timer);
  getElapsedTimeNs_print(timer);
  printf("GOT: %s\n", terminalOutput);
  pclose(fp);
  
  printf("THIS IS FGETS\n");
  printf("-----------------------\n");
  memset(output, 0, 1000);
  char current;
  int i = 0;
  timer = startTimer(); 
  fp = popen(command, "r");
  while((current = fgetc_unlocked(fp)) != -1){
    output[i] = current;
    i++;
  }
  endTimer(timer);
  getElapsedTimeNs_print(timer);
  printf("GOT: %s\n", terminalOutput);
  pclose(fp);
  return (0);
}
