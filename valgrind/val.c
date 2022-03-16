#include<stdio.h>
#include<stdlib.h>

int main()
{

 int *A;

 A = (int*)malloc(10*sizeof(int));
 

 for(int i = 1;i<=10;i++)
 {
     A[i] = i;
 }

 for(int i = 1; i<=10;i++)
 {
     printf("%d ",A[i]);
 }

 free(A);

    return 0;
}