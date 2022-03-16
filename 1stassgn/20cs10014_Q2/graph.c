#include<stdio.h>
#include <stdlib.h>
#include <libassgn1.h>
#include "graph.h"


void swap(int *x ,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}
GRAPH readGraph(char *FName)
{
    
   GRAPH g;
    
    FILE *f;
    int i,j;

    f = fopen(FName,"r");
    int a,b,c,d,e;
     if(f == NULL)
    {
        printf("unable to read the file\n");
    }

    else
    {

       fscanf(f,"%d",&a);
       g.size = a;
       fscanf(f,"%d",&b);
       g.size_of_edges = b;
       g.A = (int**)malloc(a*sizeof(int*));      //dynamic allocation of rows

       for(i = 0;i<a;i++)
       {
           g.A[i] = (int*)malloc(a*sizeof(int));  //dynamic allocation of columns
       }

       for(i=0;i<a;i++)
       {
           for(j = 0;j<a;j++)
           {
               g.A[i][j] = 0;
           }

       }



    //    //GRAPH
       while(b--)    //that many edges
       {
           fscanf(f,"%d %d %d",&c,&d,&e);   //vertices and lengths
           g.A[c][d] = e;
           g.A[d][c] = e;

       }

    }



    return g;

}


void DFS(GRAPH G)
{
    printf("DFS of given graph is : ");
    int visited[G.size],i;
    for(i = 0;i<G.size;i++)
    {
        visited[i] = 0;       //means not visited.
    }

    STACK s = createStack();

    s = push(s,0);
    while (!isEmptyStack(s))
    {
        int next;

        s = pop(s,&next);

        if(!visited[next])
        {
            visited[next] = 1;
            printf("%d ",next);

            for(i=G.size-1;i>=0;i--)
            {
                if(G.A[next][i]>0 && !visited[i])
                {
                    s = push(s,i);
                }
            }
        }
        
    }

    printf("\n");
    
}


void BFS(GRAPH G)
{
    printf("BFS of given graph is : ");

    int visited[G.size],i;
    for(i = 0;i<G.size;i++)
    {
        visited[i] = 0;
    }

int s = 0;
    QUEUE Q;
    Q = createQueue();
    printf("%d ",s);
    visited[s] = 1;
    Q = enqueue(Q,s);        //adding this  to queue

    while(!isEmptyQueue(Q))
    {
        Q = dequeue(Q,&s);
        //printf("%d ",s);

        for(i = 0; i<G.size;i++)
        {
            if(G.A[s][i]>0 && visited[i] == 0)
            {
                printf("%d ",i);
                visited[i] = 1;
                Q = enqueue(Q,i);

            }

        }


    }

    printf("\n");

}

void MST(GRAPH G)
{
    
    //int e = G.size_of_edges/2 + 1;  


    int temp = 0,i,j;
    int n = G.size;

    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(G.A[i][j] != 0)
            {
                temp++;
            }
        }
    }
    
    int e = temp/2;
    int P[e][3];
    temp = 0;

    for(i = 0;i<n;i++)
    {
        for(j = 0; j<n;j++)
        {
            if(i>j)
            {
                if(G.A[i][j] != 0 )
            {
                P[temp][0] = i;
                P[temp][1] = j;
                P[temp][2] = G.A[i][j];
                 temp = temp+1;
            }

            }
            
        }
    }

    //int a;

    for(i = 0;i<temp-1;i++)
    {
        //a = i;

        for(j = i+1;j<temp;j++)
        {
            if(P[j][2] < P[i][2])
            {
                //a = j;

            swap(&P[j][0],&P[i][0]);
            swap(&P[j][1],&P[i][1]);
            swap(&P[j][2],&P[i][2]);

            }
            
        }
    }
    

    UNION_FIND q = createUF(n);
    for(i = 0;i<n;i++)
    {
        int *f = (int*)malloc(sizeof(int));
        q = makeSetUF(q,i,f);
    }
    temp = 0; //total sum of edges of min spanning tree

    for(i = 0;i<G.size;i++)
    {
        NODE_PTR p1 = findUF(q,P[i][0]);
        NODE_PTR p2 = findUF(q,P[i][1]);

        if(p1 != p2)
        {

            temp = temp +P[i][2];
            unionUF(q,P[i][0],P[i][1]);
            printf("%d %d %d\n", P[i][0],P[i][1],P[i][2]);
        }
    }

    printf("sum of edges in minimum spanning tree is %d\n",temp);
    

   //printf("Working fine till now\n");

}
/*
int main()
{
   
  GRAPH p =  readGraph("chennagraph.txt");

  printf("%d\n",p.size);

  int i,j;

  for(i = 0;i<p.size;i++)
  {
      for(j = 0;j<p.size;j++)
      {
          printf("%d ", p.A[i][j]);
      }
      printf("\n");
  }

  DFS(p);
  BFS(p);
  MST(p);

}

*/
