#include<stdio.h>
#include<stdlib.h>
#include "union_find.h"

UNION_FIND createUF(int n)
{
    UNION_FIND p;

    p.A = (NODE_PTR*)malloc(n*sizeof(NODE_PTR));         

    p.size = 0;   // a temporary one to take care how many are filled.
 
    return p;
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int *i)
{
    
        int k;
    F.size++;       //keeps track of newly inserting position.
    k = F.size-1;
    NODE_PTR p;

    p = (NODE_PTR)malloc(sizeof(struct node_ptr));
    p->value = x;
    p->next = NULL;      
    F.A[k] = p;
    *i = k;
    return F;
    
}


NODE_PTR findUF(UNION_FIND F, int i)
{
    NODE_PTR p;
    p = F.A[i];
    p->rank = 0;

    while(p->next != NULL)
    {
        p = p->next;
        p->rank = p->rank + 1;

    }

    return p;
}

void unionUF(UNION_FIND F, int i, int j)
{
    NODE_PTR p1;
    NODE_PTR p2;

    p1 = findUF(F,i);

    p2 = findUF(F,j);

    if((p1->rank)>(p2->rank))
    {
        p2->next = p1;
    }
    else
    {
        p1->next = p2;
    }

}
/*
int main()
{

    UNION_FIND UF = createUF(8);
	int index[9];
    
	UF = makeSetUF(UF, 34, &index[0]);
	UF = makeSetUF(UF, 19, &index[1]);
    
	UF = makeSetUF(UF, 5, &index[2]);
	UF = makeSetUF(UF, 23, &index[3]);
	UF = makeSetUF(UF, 11, &index[4]);
	UF = makeSetUF(UF, 47, &index[5]);
	UF = makeSetUF(UF, 9, &index[6]);
	UF = makeSetUF(UF, 28, &index[7]);

	for(int i=0;i<8;i++)
	{
		printf("%d\n", index[i]);
	}

	unionUF(UF, index[0], index[5]);
	printf("%d %d\n",findUF(UF, index[0])->value, findUF(UF, index[5])->value);
	unionUF(UF, index[0], index[6]);
	printf("%d %d\n",findUF(UF, index[0])->value, findUF(UF, index[6])->value);
	unionUF(UF, index[1], index[7]);
	printf("%d %d\n",findUF(UF, index[1])->value, findUF(UF, index[7])->value);
	unionUF(UF, index[2], index[7]);
	printf("%d %d\n",findUF(UF, index[2])->value, findUF(UF, index[7])->value);
	unionUF(UF, index[4], index[7]);
	printf("%d %d\n",findUF(UF, index[4])->value, findUF(UF, index[7])->value);
	printf("%d\n",findUF(UF, index[3])->value);

	UF=makeSetUF(UF, 10, &index[8]);
    
    
}


*/