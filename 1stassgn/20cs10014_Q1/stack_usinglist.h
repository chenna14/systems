// #include "linklist.h"
typedef struct node *STACK;

STACK createStack();
int isEmptyStack(STACK S);
STACK push(STACK S,int k);
STACK pop(STACK S,int *k);
void printSTACK(STACK H);
