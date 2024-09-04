#include <stdlib.h>
static int mallocCount = 0;
static long long mallocSize = 0;



void * countMalloc(size_t size){
  mallocCount++;
  //mallocSize += size;
  return(malloc(size));
}


void countFreeMalloc(void* data){
  mallocCount--;
  //mallocSize -= sizeof(data);
  free(data);
}


int getMallocCount(void){
  return(mallocCount);
}


long long getMallocSize(void){
  return(mallocSize);
}



