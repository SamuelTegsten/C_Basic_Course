#include <stdio.h>

int main ()
{

    int fraction1, fraction2, sum_of_fractions1, gcd, sum_fraction1, sum_fraction2;    
    printf("Enter a Fraction:\n");
    scanf("%d", &fraction1);
    scanf("%d", &fraction2);

    for(sum_of_fractions1 = 1; sum_of_fractions1 <= fraction1 && sum_of_fractions1 <= fraction2; ++sum_of_fractions1)
    {
        if(fraction1 %sum_of_fractions1 == 0 && fraction2%sum_of_fractions1 == 0)

        gcd = sum_of_fractions1;
    
    }

    sum_fraction1 = fraction1 / gcd;
    sum_fraction2 = fraction2 / gcd;

    printf("In lowest terms: %d/%d\n" , sum_fraction1, sum_fraction2);
    return 0;
}