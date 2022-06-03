#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
int main ()
{
    int digit, digit1, digit2, digit3, digit4;
    bool digit_seen[10] = {false};
    long n;
    int sum, divider;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0)
    {
        digit = n % 10;
        if(digit_seen[digit])
        {
        break;
        }
        bool digit_seen[digit] = true;
        n = n/10; 
    }
    if (n > 0)
    {
        while (n > 0)
    {
        digit1 = (n/10) % 10;
        if(digit_seen[digit1])
        {
        break;
        }
        digit_seen[digit1] = true;
        n = n/10; 
    }
        while (n > 0)
    {
        digit2 = (n/100) % 10;
        if(digit_seen[digit2])
        {
        break;
        }
        digit_seen[digit2] = true;
        n = n/10; 
    }           
            while (n > 0)
    {
        digit3 = (n/1000) % 10;
        if(digit_seen[digit3])
        {
        break;
        }
        digit_seen[digit3] = true;
        n = n/10; 
    }       
            while (n > 0)
    {
        digit4 = (n/10000) % 10;
        if(digit_seen[digit4])
        {
        break;
        }
        digit_seen[digit4] = true;
        n = n/10; 
    }       
           
           
            printf("The repeted digits: %d %d %d %d %d", digit, digit1, digit2, digit3, digit4);
    }
    else
    {
        printf("No repeat digit(s)\n");
    }
    return 0;
}