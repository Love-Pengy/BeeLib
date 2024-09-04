#pragma once
#include <stdlib.h>
void *countMalloc(size_t);
void countFreeMalloc(void *);
int getMallocCount(void);
long long getMallocSize(void);
