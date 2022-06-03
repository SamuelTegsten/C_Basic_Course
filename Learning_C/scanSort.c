#include<stdio.h>
int main()
{
   int min,max,a,b,c,d;

   printf("enter any four intergers: \n");
   scanf("%d%d%d%d",&a,&b,&c,&d);

   min=a;
   max=a;
   if(min>b) 
      min=b;
   else if(max<b)
      max=b;
   if(min>c) 
      min=c;
   else if(max<c)
      max=c;
   if(min>d) 
      min=d;
   else if(max<d)
      max=d;
      
   printf("Largest number:%d \n Smallest number:%d\n", max , min);

   return 0;
}
