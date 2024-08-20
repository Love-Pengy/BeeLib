#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum dataType { UNINITIALIZED, INTEGER, STRING, FLOAT, DOUBLE };

struct nodeType {
  struct nodeType *next;
  type unionType;
  union {
    int iData;
    char *sData;
    float fData;
    double dData;
  };
};

node createLList(void) {
  node output = malloc(sizeof(struct nodeType));
  output->next = NULL;
  output->unionType = UNINITIALIZED;
  return (output);
}

void appendLList(node head, void *data, type dType) {
  node addition = createLList();
  addition->unionType = dType;
  addition->next = NULL;
  switch (*dType) {
  case INTEGER:
    addition->iData = *(int *)data;
    break;
  case STRING:
    addition->sData = malloc(sizeof(char) * strlen(*(char **)data));
    addition->sData[0] = '\0';
    strncpy(addition->sData, (char *)data, strlen(*(char **)data));
    break;
  case FLOAT:
    addition->fData = *(float *)data;
    break;
  case DOUBLE:
    addition->dData = *(double *)data;
    break;
  default:
    fprintf(stderr, "%s (%d): UNITIALIZED VALUE APPENDED\n", __FILE__,
            __LINE__);
    return;
  }

  node ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = addition;
}

void printLList(node llist) {
  node ptr = llist;
  printf("{ ");
  while (ptr->next) {
    switch (*(ptr->unionType)) {
    case INTEGER:
      printf("%d ", ptr->iData);
      break;
    case STRING:
      printf("%s ", ptr->sData);
      break;
    case FLOAT:
      printf("%f ", ptr->fData);
      break;
    case DOUBLE:
      printf("%f ", ptr->dData);
      break;
    default:
      printf("NULL ");
      return;
    }
  }
  printf("}\n");
}
