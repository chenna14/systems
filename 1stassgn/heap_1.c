#include<stdio.h>
#include<stdlib.h>
#include "heap_1.h"


int PARENT(int i)
{
    return (i-1)/2;
}

void swap(int *x ,int *y)     //swap function may be added in library if required.
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}


HEAP createHeap()
{
    HEAP h;

    h.count = 0;

    h.A = (int*)malloc(100*sizeof(int));

    return h;
}
int findMin(HEAP H)     //just the root element
{

if(H.count == 0)
  {
    printf("Heap is empty so cannot find the minimum\n");
    return 0;
  }
else
  {
    return H.A[0];
  }

}


void heapify(HEAP H,int i)      //heapifing the disturbed heap structure.
{
    int x = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    
    if (l < H.count && H.A[l] < H.A[x])
        x = l;
 
    
    if (r < H.count && H.A[r] < H.A[x])
        x = r;
 
    
    if (x != i) {
        swap(&H.A[i], &H.A[x]);
 
        heapify(H,x);
    }
}


HEAP extractMin (HEAP H)
{
    if(H.count == 0)
    {
        printf("Heap is empty so cannot delete the minimum\n");
        return H;
    }
    else if(H.count == 1)
    {
        H.count--;
        return H;
    }
    else
    {

        H.A[0] = H.A[H.count-1];  //replace the root one with last one because it is the minimum one.
        H.count--;

         heapify(H,0);           


         return H;
    }

}
HEAP insertHeap(HEAP H, int k)
{
    if(H.count == 100)
    {
        printf("Heap is full so cannot add anymore\n");

        return H;
    }

    H.count++;
    


    int i = H.count -1;

    H.A[i] = k;

    while(i!=0 && (H.A[PARENT(i)]>H.A[i]))
    {
        swap(&H.A[PARENT(i)] , &H.A[i]);

        i = PARENT(i);
    }

    return H;
    

}
int isFullHeap(HEAP H)  //just compare with the count we took
{
    if(H.count == 100)
    {
        return 1;
    }
    
    return 0;
}
int isEmptyHeap(HEAP H)
{
    if(H.count == 0)
    {
        return 1;

    }

    return 0;
}



void print(HEAP H)
{
    int i,l = H.count;

    for(i = 0;i<l;i++)
    {
        printf("%d ",H.A[i]);

    }
}

/*
int main()
{
     HEAP x = createHeap();
     
     x = insertHeap(x,2);
     
     x = insertHeap(x,7);

     x = insertHeap(x,1);

     x= insertHeap(x,4);

     x = insertHeap(x,11);
     x = insertHeap(x,75);
     x = insertHeap(x,8);
     x = insertHeap(x,3);
     x = insertHeap(x,-1);
     x = extractMin(x);
     
    //  x = insertHeap(x,15);
    //  x = insertHeap(x,74);
    //  x = insertHeap(x,41);
    //  x = insertHeap(x,6);
    // int a = isFullHeap(x);
    // printf("%d",a);
    print(x);

    return 0;
}
*/