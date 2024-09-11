#include <stdlib.h>

void bubbleSort(int* arr, int size){
  if(arr == NULL){
    return;
  }
  int count = 1;
  while(count){ 
    count = 0;
    for(int i = 0; i < (size-1); i++){
      if(arr[i] > arr[i+1]){
        arr[i] ^= arr[i+1];
        arr[i+1] ^= arr[i];
        arr[i] ^= arr[i+1];
        count++;
      }
    }
    if(!count){
      break;
    }
  }
}


