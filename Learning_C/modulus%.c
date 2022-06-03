#include <stdio.h>

int main ()
{
    /*
    * Displaying a number in reverse -> ex: 123 -> 321
    */ 

    int number1;
    printf("Enter a three-digigt number:\n");
    scanf("%d", &number1);
    int sum1 = number1 / 100;    
    int sum2 = number1 % 100;
    int sum3 = number1 % 100;

    printf("The reversal is:%d%d%d\n", sum3, sum2, sum1);

    return 0;
}