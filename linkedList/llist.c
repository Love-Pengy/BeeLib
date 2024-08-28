#include "llist.h"
#include <stdbool.h>
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

node createLListNode(void) {
  node output = malloc(sizeof(struct nodeType));
  output->next = NULL;
  output->unionType = UNINITIALIZED;
  return (output);
}

void appendToLList_int(node head, void *data) {
  if (head->unionType == UNINITIALIZED) {
    head->unionType = INTEGER;
    head->iData = *(int *)data;
    return;
  }
  node addition = createLListNode();
  addition->unionType = INTEGER;
  addition->iData = *(int *)data;
  if (head == NULL) {
    head = addition;
    return;
  }
  node ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = addition;
}

void appendToLList_string(node head, void *data) {
  if (head->unionType == UNINITIALIZED) {
    head->unionType = STRING;
    head->sData = malloc(sizeof(char) * (strlen((char *)data) + 1));
    strncpy(head->sData, (char *)data, strlen((char *)data));
    return;
  }
  node addition = createLListNode();
  addition->unionType = STRING;
  addition->sData = malloc(sizeof(char) * (strlen((char *)data) + 1));
  strncpy(addition->sData, (char *)data, strlen((char *)data));
  if (head == NULL) {
    head = addition;
    return;
  }
  node ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = addition;
}

void appendToLList_float(node head, void *data) {
  if (head->unionType == UNINITIALIZED) {
    head->unionType = FLOAT;
    head->fData = *(float *)data;
    return;
  }
  node addition = createLListNode();
  addition->unionType = FLOAT;
  addition->fData = *(float *)data;
  if (head == NULL) {
    head = addition;
    return;
  }
  node ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = addition;
}

void appendToLList_double(node head, void *data) {
  if (head->unionType == UNINITIALIZED) {
    head->unionType = DOUBLE;
    head->dData = *(double *)data;
    return;
  }
  node addition = createLListNode();
  addition->unionType = DOUBLE;
  addition->dData = *(double *)data;
  if (head == NULL) {
    head = addition;
    return;
  }
  node ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = addition;
}

void printLList(node llist) {
  if (llist == NULL || llist->unionType == UNINITIALIZED) {
    printf("{ }\n");
    return;
  }
  node ptr = llist;
  int count = 0;
  printf("{ ");
  while (ptr) {
    if (count) {
      printf(", ");
    }
    switch (ptr->unionType) {
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
      goto end;
    }
    ptr = ptr->next;
    count |= 1;
  }
end:
  printf("}\n");
}

void prependToLList_int(node *head, void *data) {
  if ((*head)->unionType == UNINITIALIZED) {
    (*head)->unionType = INTEGER;
    (*head)->iData = *(int *)data;
    return;
  }
  node output = createLListNode();
  output->unionType = INTEGER;
  output->iData = *(int *)data;
  if ((*head) == NULL) {
    (*head) = output;
    return;
  }
  output->next = (*head);
  (*head) = output;
}

void prependToLList_string(node *head, void *data) {
  if ((*head)->unionType == UNINITIALIZED) {
    (*head)->unionType = STRING;
    (*head)->sData = malloc(sizeof(char) * (strlen((char *)data) + 1));
    strncpy((*head)->sData, (char *)data, strlen((char *)data));
    return;
  }
  node output = createLListNode();
  output->unionType = STRING;
  output->sData = malloc(sizeof(char) * (strlen((char *)data) + 1));
  strncpy(output->sData, (char *)data, strlen((char *)data));
  if ((*head) == NULL) {
    (*head) = output;
    return;
  }
  output->next = (*head);
  (*head) = output;
}

void prependToLList_float(node *head, void *data) {
  if ((*head)->unionType == UNINITIALIZED) {
    (*head)->unionType = FLOAT;
    (*head)->fData = *(float *)data;
    return;
  }
  node output = createLListNode();
  output->unionType = FLOAT;
  output->fData = *(float *)data;
  if ((*head) == NULL) {
    (*head) = output;
    return;
  }
  output->next = (*head);
  (*head) = output;
}

void prependToLList_double(node *head, void *data) {
  if ((*head)->unionType == UNINITIALIZED) {
    (*head)->unionType = DOUBLE;
    (*head)->dData = *(double *)data;
    return;
  }
  node output = createLListNode();
  output->unionType = DOUBLE;
  output->dData = *(double *)data;
  if ((*head) == NULL) {
    (*head) = output;
    return;
  }
  output->next = (*head);
  (*head) = output;
}

void freeLList(node head) {
  node holdPtr = head->next;
  node freePtr = head;
  while (freePtr->next != NULL) {
    if (freePtr->unionType == STRING)
      free(freePtr->sData);
    free(freePtr);
    freePtr = holdPtr;
    holdPtr = freePtr->next;
  }
  if (freePtr->unionType == STRING)
    free(freePtr->sData);
  free(freePtr);
  head = NULL;
}

void freeFirstNode(node head) {
  if (!head) {
    return;
  }
  node holdPtr = head->next;
  node freePtr = head;
  if (holdPtr == NULL) {
    if (freePtr->unionType == STRING)
      free(freePtr->sData);
    free(freePtr);
    freePtr = NULL;
    return;
  }
  if (freePtr->unionType == STRING)
    free(freePtr->sData);
  free(freePtr);
  head = holdPtr;
}

void popLList(node head) {
  if(!head){
    return;
  }
  node prev = NULL;
  node target = head;
  if(!(target->next)){
    freeFirstNode(target);
    return;
  }
  while(target->next){
    prev = target;
    target = target->next;
  }
  if (target->unionType == STRING)
    free(target->sData);
  free(target);
  prev->next = NULL;
}
