#include <stdio.h>

int main ()
{

    int divisor1, divisor2, fdivisors1, sum_of_divisors2;    
    printf("Enter two Intergers:\n");
    scanf("%d", &divisor1);
    scanf("%d", &divisor2);

    for(fdivisors1 = 1; fdivisors1 <= divisor1 && fdivisors1 <= divisor2; ++fdivisors1)
    {
        if(divisor1 % fdivisors1 == 0 && divisor2 % fdivisors1 == 0)

        sum_of_divisors2 = fdivisors1;
    
    }

printf("Greatest common divisor: %d\n", sum_of_divisors2);
return 0;
}