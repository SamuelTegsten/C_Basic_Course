#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main ()
{
    int arrayrand[2], i, random1, random2;
    srand(time(NULL));
    printf("Storing 2 random Intergers\n");

    for(i = 0; i < 1; i++)
    {
        random1 = rand();
    }
        for(i = 0; i < 1; i++)
    {
        random2 = rand();
    }
    if(random1 > random2)
    {
        printf("%d, %d \n", random1, random2);
    }
    else
    {
        printf("%d, %d \n", random2, random1);
    }
}