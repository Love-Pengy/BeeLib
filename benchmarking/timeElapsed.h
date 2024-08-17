#pragma once 

#include <stdint.h>
#include <sys/time.h>
typedef struct timeObj {
  struct timeval startTime;
  struct timeval endTime;
} bench;

bench* startTimer(void);
void endTimer(bench *);
uint64_t getElapsedTimeMs(bench *);
uint64_t getElapsedTimeUs(bench *);
uint64_t getElapsedTimeS(bench *);
void freeTimer(bench**);
