#include<stdio.h>
#include<stdlib.h>


double trea(int x1,int x2,int x3,int y1,int y2,int y3)
{
    double area;
    area = x1 * (y2-y3);
    area += x2 * (y1-y3);
    area += x3 * (y1-y2);

    if(area<0) area = -area;

    area = area/2;

    return area;
}
int main()
{

    int x1,x2,x3,y1,y2,y3;

    

    printf("progream to calc area\n");

    printf("enter first co-ordinate\n");

    scanf("%d%d", &x1,&y1);

    printf("enter second co-ordinate\n");

    scanf("%d%d", &x2,&y2);

    printf("enter third co-ordinate\n");

    scanf("%d%d", &x3,&y3);

   double area = trea(x1,x2,x3,y1,y2,y3);

    printf("area of traingle is %lf\n",area);
}