#ifndef DYNAMICARRAY
#define DYNAMICARRAY

typedef struct listType *list;
list createList(void);
void expandList(list*);
void listAppendString(list*, char*);
void listAppendList(list*, list);
void freeList(list);
char* listToString(list);
void printList(list);
void prependString(list*, char*);

#endif
