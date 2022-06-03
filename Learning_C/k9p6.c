#include <stdio.h> 

int function(int x)
{
    int polynomial;
    polynomial = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6; 
    return polynomial;
}
int main ()
{
    int x;
    printf("Please enter a Interger for x: ");
    scanf("%d", &x);
    printf("\n");
    int result = function(x);
    printf("Result: %d", result);
    return 0;
}