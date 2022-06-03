#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#define N 5

int random_numbers (int v[], int x);

int main ()
{
    int v = 5;
    int n[N] = random_numbers(v);
    int i;

    for(i = 0 ; i < n[N] ; i++)
    {
        int j,tmp;
        for ( i = 0 ; i < n[N] -1 ;i++)
        {
            for(j = 0 ; j < n[N] -1 -i ;j++)
            {
                if(n[j] > n[j + 1])
                {
                    tmp = n [j] ;
                    n[j] = n[j + 1];
                    n[j + 1] = tmp;
                }
            }
        }
    }
for ( i = 0 ; i < n[N] ; i++) printf("%d,",n[i]);
printf("\n");
}

int random_numbers (int v[])
{
    int i;
    random_numbers = v[0]
    srand(time(NULL)); 
    for(i = 0; i < N; i++)
    {
        random_numbers[i] = rand() % 100 + 1;
    }
    return random_numbers;
}