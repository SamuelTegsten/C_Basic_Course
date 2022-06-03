#include <stdio.h>
#include <stdlib.h>


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void sort(int values[], int n)
{
    int test =5;
printf("Before sorting the list is: \n");
   for( n = 0 ; n < test; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, test, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < test; n++ ) {   
      printf("%d ", values[n]);
   }
}
int main () {
int n;
int values[] = { 88, 56, 100, 2, 25 };
sort(values, n);
  
   return(0);
}
