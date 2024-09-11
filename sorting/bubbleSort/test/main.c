#include <stdio.h>
#include "../bubbleSort.h"

int main(void){
int test[] = {0, 10, 14, 2, -1};
printf("Start: ");
for(int i = 0; i < 5; i++){
  printf("%d ", test[i]);
}
printf("\n");
bubbleSort(test, 5);
printf("End: ");
for(int i = 0; i < 5; i++){
  printf("%d ", test[i]);
}
return(0);
}
