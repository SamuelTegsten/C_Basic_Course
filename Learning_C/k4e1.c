#include <stdio.h>

int main ()
{
int i = 5;
int j = 3;
printf("%d %d\n",i/j, i % j);

int a = 2;
int b = 3;
printf("%d\n", (a+10) %b);

int c = 7;
int d = 8;
int e = 9;
printf("%d\n", (c+10) %e/d);

int f = 1;
int g = 2;
int h = 3;
printf("%d\n", (f+5) % (g+2) / h);
return 0;
}
