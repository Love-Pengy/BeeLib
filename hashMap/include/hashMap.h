#pragma once

#include "../lib/include/boardingPassExample.h"
#include "../lib/include/hashTable.h"
typedef struct hashMapType* hashMap;
hashMap createHashMap(void);
void removeElementHM(hashMap*, char*);
void addElementHM(hashMap*, char*, boardingPass);
boardingPass findValueHM(hashMap, char*);
void printHM(hashMap);
