#include<stdio.h>
#include<stdlib.h>
#include "defs.h"
#include "linked_list.h"
#include "queue_usinglist.h"
typedef struct node *QUEUE;     //FIRST IN FIRST OUT


QUEUE createQueue()
{

    QUEUE p;

    p = (QUEUE)malloc(sizeof(node)); // node* is also list

    p->value = '\0';
    p->next = NULL;
    return p;
}
int isEmptyQueue(QUEUE Q)
{
    if(Q->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
QUEUE enqueue(QUEUE Q, int k)    //INSERT AT FIRST
{
    QUEUE temp = (QUEUE)malloc(sizeof(node));
    temp->value = k;
    temp->next = Q->next;
    Q->next = temp;

    return Q;
}
QUEUE dequeue(QUEUE Q, int *k)       //DELETE FROM LAST
{
    if (Q == NULL)
    {
        printf("End element cannot be deleted because the list is empty\n");
        return Q;
    }
    node *p = Q, *temp = Q; // is considering only 1 element case required?

    while (p->next != NULL)
    {
        p = p->next;
    }
    *k = p->value;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;

    return Q;
}

void printQUEUE(QUEUE H)
{

    QUEUE p;
    p = H->next;
    while (p != NULL)
    {
        printf("%d\n", p->value);
        p = p->next;
    }
}

/*
int main()
{
    QUEUE x = createQueue();

    x = enqueue(x,1);
    x = enqueue(x,2);
    x = enqueue(x,3);

    int a;
    dequeue(x,&a);

    //printQUEUE(x);
    //printf("%d\n",a);


}
*/