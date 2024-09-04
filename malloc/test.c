#include "countMalloc.h"
#include <stdio.h>


int main (void){
  char* random = countMalloc(sizeof(char) * 100);
  char* random1 = countMalloc(sizeof(char) * 100);
  printf("%d | %lld\n", getMallocCount(), getMallocSize());
  countFreeMalloc(random);
  printf("%d | %lld\n", getMallocCount(), getMallocSize());
}
