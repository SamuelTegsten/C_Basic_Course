#include <stdio.h>
int main ()
{
int num1, denom1, num2, denom2, result_num, result_denom;
printf("Add (+) two fractions and get the sum: ");
scanf("%d/%d + %d/%d", &num1, &denom1, &num2, &denom2);

result_num = num1 * denom2 + num2 * denom1;
result_denom = denom1 * denom2;

printf("the sum is %d/%d\n", result_num, result_denom);



return 0;
}