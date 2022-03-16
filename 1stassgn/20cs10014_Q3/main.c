#include<stdio.h>
#include<stdlib.h>
#include <libassgn1.h>
#include <libassgn2.h>


int main()
{
    char *f;
    printf("enter directory of the file\n");
    f  = (char*)malloc(100*sizeof(char));
    scanf("%s",f);

    GRAPH g = readGraph(f);
    DFS(g);
    printf("\n");
    BFS(g);
    printf("\n");
    MST(g);
    printf("\n");

}