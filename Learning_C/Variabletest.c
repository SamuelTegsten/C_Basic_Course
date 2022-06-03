#include <stdio.h>
int main ()
{

char characterName[] = "John";
int characterAge = 35;

printf ("%d\n", characterAge);
characterAge = 45;
printf ("%d\n", characterAge);
characterAge = 55;
printf ("%d\n", characterAge);

printf ("test för nummersekvens &d\n", characterAge);
printf ("Som sedan konternueligt anvands till %d\n", characterAge);
characterAge = 100;
printf ("Som nu nadde %d ar gammal!\n", characterAge);

return 0;
}
