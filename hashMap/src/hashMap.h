#pragma once
#include "../lib/include/boardingPassExample.h"
#include "../lib/include/hashTable.h"
typedef struct hashMapType* hashMap;
boardingPass findValueHM(hashMap, char*);
void removeElementHM(hashMap*, char*);
void addElementHM(hashMap*, char*, boardingPass);
hashMap createHashMap(hashTable);
