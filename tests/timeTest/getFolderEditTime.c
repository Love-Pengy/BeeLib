#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  struct stat attr;
  stat("/home/bee/Projects/git-stats/", &attr);
  struct tm *output = malloc(sizeof(struct tm));
  errno = 0;
  output = localtime(&attr.st_mtim.tv_sec);
  if (errno) {
    perror("getModifiedTime");
  }
  struct tm val = *(output);
  return (0);
}
