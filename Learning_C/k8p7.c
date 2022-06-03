#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
int main ()
{
#define N 5
int z[N][N];
int a , b, d, c=0 ,e=0 ,f=0 ,g=0 ,h=0 ,c2=0 ,e2=0 ,f2=0, g2=0, h2=0; 

printf("Enter rows\n");
     
     for (b=0; b<N; b++)
    {
               for (a=0; a<N; a++)
                { 
                scanf("%d", &z[a][b]);
                }
    }
    for (d=0; d<N; d++)
    {
        c += z[d][0];
        e += z[d][1];
        f += z[d][2];
        g += z[d][3];
        h += z[d][4];
    }
    for (d=0; d<N; d++)
    {
        c2 += z[0][d];
        e2 += z[1][d];
        f2 += z[2][d];
        g2 += z[3][d];
        h2 += z[4][d];
    }
printf("Total of rows is %d %d %d %d %d\n", c,e,f,g,h);
printf("Total of columns is %d %d %d %d %d\n", c2,e2,f2,g2,h2);
}