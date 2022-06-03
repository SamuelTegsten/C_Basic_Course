#include <stdio.h>
int main ()
{
    int weekday; //0 -> måndag, 1 -> tisdag, 2 -> onsdag 3 -> torsdag, 4 -> fredag, 5 -> lordag, -> sondag//
    int nrofdays;

    printf("Vilken veckodag är det 0-6 man-son"\n);
    scanf("%d", &weekday);
    printf("om hur manga dagar vill du veta veckodagen\n");
    scanf("%d", &nrofdays);

    while(nrofdays>=7)

    {
        nrofdays = nrofdays-7;
    }

    int result;
    result = weekdays + nrofdays;

    if(result >= 7)
    {
        result = result - 7;
    }

    if(result == 0)
    {
        printf("Det är mandag\n");
    }

    else if(result == 1)
    {
        printf("Det är tisdag\n");
    }

    else if(result == 2)
    {
        printf("Det är onsdag\n");
    }

    else if(result == 3)
    {
        printf("Det är torsdag\n");
    }

    else if(result == 4)
    {
        printf("Det är fredag\n");
    }
    else if(result == 5)
    {
        printf("Det är lordag\n");
    }
    else if(result == 6)
    {
        printf("Det är sondag\n");
    }
    
    return 0;
}