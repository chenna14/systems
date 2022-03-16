#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "linked_list.h"



typedef struct node *LLIST;
LLIST createList()
{
    LLIST p;

    p = (LLIST)malloc(sizeof(node)); // node* is also list

    //p->value = '\0';
    
    //p->next = NULL;

    p = NULL;
    return p;
}

int searchList(LLIST H, int k)
{
    node *p = H;

    while (p != NULL)
    {
        if (p->value == k)
        {
            return 1;
        }

        p = p->next;
    }

    return 0;
}



LLIST insertAtFront(LLIST H, int k)
{
    LLIST temp = (LLIST)malloc(sizeof(node));         //just a temperory one 
    temp->value = k;
    temp->next = H;
    H = temp;

    return H;
}

LLIST insertAtEnd(LLIST H, int k)     // go to last and insert
{
    node *p, *temp;

    p = H;

    while (p->next != NULL)
    {
        p = p->next;
    }

    temp = (node *)malloc(sizeof(node));
    temp->value = k;
    temp->next = NULL;

    p->next = temp;

    return H;
}

LLIST deleteFromFront(LLIST H, int *k)
{
    if (H == NULL)
    {
        printf("Front element cannot be deleted because the list is empty\n");
        return H;
    }
    *k = H->value;
    H = H->next;
    return H;
}

LLIST deleteFromEnd(LLIST H, int *k)
{
    if (H == NULL)
    {
        printf("End element cannot be deleted because the list is empty\n");
        return H;
    }
    node *p = H, *temp = H; // is considering only 1 element case required?

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

    return H;
}

LLIST deleteList(LLIST H, int k)
{
    if (H == NULL)
    {
        printf("element cannot be deleted because the list is empty\n");
        return H;
    }

    node *p;

    p = H;
/*
    while (p->next->next != NULL)
    {
        if (p->next->value == k)
        {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    */
   while (p->next != NULL)
    {
        if (p->value == k)
        {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }


    return H;
}

void printlist(LLIST H)
{

    LLIST p;
    p = H;
    while (p != NULL)
    {
        printf("%d\n", p->value);
        p = p->next;
    }
}
/*
int main()
{

    LLIST x;
    x = createList();
    // x = insertAtEnd(x,2);
    // x = insertAtFront(x, 8);
    // x = insertAtFront(x, 5);
    // x = insertAtFront(x,3);
    // int a;
    //x = deleteFromFront(x,&a);
    //  x = insertAtEnd(x, 7);
    // x = insertAtEnd(x, 9);
    //printlist(x);

     

    // x = deleteFromFront(x,&a);
    // printf("%d\n",a);
    // x = deleteFromEnd(x,&a);
    //printf("%d\n",a);
    //x = deleteFromFront(x,&a);
    //printf("%d\n",a);
    x = deleteList(x,3);


    printlist(x);
}
*/