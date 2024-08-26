#include "logging.h"
#include <stdarg.h>
#include <stdio.h>

void logErr(char *file, int line, char *formatString, ...) {
  va_list list;
  va_start(list, formatString);
  char buff[4096];
  vsnprintf(buff, 4096, formatString, list);
  fprintf(stderr, "%s (%d): %s\n", file, line, buff);
  va_end(list);
}

void logWarn(char *file, int line, char *formatString, ...) {
  va_list list;
  va_start(list, formatString);
  char buff[4096];
  vsnprintf(buff, 4096, formatString, list);
  fprintf(stdout, "[WARNING]: %s\n", buff);
  va_end(list);
}

void fileLog(char* file, int line, char *formatString, ...) {
  va_list list;
  va_start(list, formatString);
  char buff[4096];
  vsnprintf(buff, 4096, formatString, list);
  FILE *fptr = fopen(LOGFILE, "a");
  fprintf(fptr, "%s\n", buff);
  fclose(fptr);
  va_end(list);
}
