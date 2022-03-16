#include<stdio.h>
#include<stdlib.h>
#include "defs.h"
#include "stack_usinglist.h"
//#include "linked_list.h"




STACK createStack()
{
    STACK c = (STACK)malloc(sizeof(node));
    c->value = '\0';
    c->next = NULL;
    return c;
}



int isEmptyStack(STACK S)
{
    if(S->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


STACK push(STACK S,int k)        //push at top
{
    node *p, *temp;

    p = S;

    while (p->next != NULL)
    {
        p = p->next;
    }

    temp = (node *)malloc(sizeof(node));
    temp->value = k;
    temp->next = NULL;

    p->next = temp;

    return S;
}

STACK pop(STACK S,int *k)             //pop the top
{
    if (S->next == NULL)
    {
        printf("End element cannot be deleted because the list is empty\n");
        return S;
    }
    node *p = S, *temp = S; // is considering only 1 element case required?

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

    return S;
}

void printSTACK(STACK H)
{

    int a;
    node* ptr=H->next;
    while(ptr != NULL)
    {
        a=ptr->value;
        printf("%d\n",a);
        ptr=ptr->next;
    }
}

/*
int main()
{
    STACK x = createStack();
    x = push(x,1);
    x = push(x,3);
    x = push(x,5);

    

    int a;
    x= pop(x,&a);
    printf("%d\n",a);
     x= pop(x,&a);
     printf("%d\n",a);
      x= pop(x,&a);
      printf("%d\n",a);
      x= pop(x,&a);
      printf("%d\n",a);
      
    
    
    //printf("%d\n",a);
printSTACK(x);

}
*/