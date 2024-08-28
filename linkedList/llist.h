#pragma once
#include <stdio.h>
typedef enum dataType type;

typedef struct nodeType *node;
node createLListNode(void);
void printLList(node);

void appendToLList_int(node, void *);
void appendToLList_string(node, void *);
void appendToLList_float(node, void *);
void appendToLList_double(node, void *);

// TOOD: seperate const char and malloced char they interact wth void pointers
// diff
#define llistAppend(X, Y)                                                      \
  _Generic((Y),                                                                \
      char *: appendToLList_string((X), ((void *)Y)),                          \
      int: appendToLList_int((X), ((void *)&Y)),                               \
      float: appendToLList_float((X), ((void *)&Y)),                           \
      double: appendToLList_double((X), ((void *)&Y)),                         \
      default: fprintf(stderr, "Unknown Type Passed To Append\n"))

void prependToLList_int(node *, void *);
void prependToLList_string(node *, void *);
void prependToLList_float(node *, void *);
void prependToLList_double(node *, void *);

#define llistPrepend(X, Y)                                                     \
  _Generic((Y),                                                                \
      char *: prependToLList_string((&X), ((void *)&Y)),                       \
      int: prependToLList_int((&X), ((void *)&Y)),                             \
      float: prependToLList_float((&X), ((void *)&Y)),                         \
      double: prependToLList_double((&X), ((void *)&Y)),                       \
      default: fprintf(stderr, "Unknown Type Passed To Prepend\n"))


void freeFirstNode(node);
void freeLList(node);
