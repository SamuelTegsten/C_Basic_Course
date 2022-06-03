#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define WORDLENGTH 30
#define MAX 100
struct car
{
    char model[WORDLENGTH];
    int milage;
};
typedef struct car Car;
void printCar(Car c)
{
    printf("Bil: %s\n",c.model);
}
    Car createCar(char model[],int year, int milage)
{
    Car c;
    strcpy(c.model,model);
    c.milage=milage;
    return c;
}
void regCars(Car reg[],int *pNrOfCars)
{
    char again[WORDLENGTH] = "ja", model[WORDLENGTH];
    int year,milage;
    while(strcmp(again,"ja")==0)
    { 
        printf("Ange model:");
        scanf("%s%*c",model);
        reg[*pNrOfCars]=createCar(model,year,milage);
        (*pNrOfCars)++;
        printf("Vill du fortsatta? (ja/nej)");
        scanf("%s%*c",again);
    }
}
void printRegister(Car reg[], int nrOfCars)
{
    for(int i=0;i<nrOfCars;i++)
    {
        printCar(reg[i]);
    }
}
int main ()
{
    int nrOfCars =0;
    Car carRegister[MAX];
    int nr_val;
    for(int i=0;i<i+1;i++)
    {
        printf("Tryck 1: Registrera bilar \nTryck 2: Skriv ut alla bilar \nTryck 3: Ange mil:\nTryck 4: Avsluta\n");
        scanf("%d", &nr_val);
        if(nr_val==1)
        {
            regCars(carRegister,&nrOfCars);
        }
        if(nr_val==2)
        {
            printRegister(carRegister, nrOfCars);
        }
        if(nr_val==3)
        {

        }
        if(nr_val==4)
        {
            break;
        }
        if(nr_val >=5)
        {
            printf("Du maste ange ett nummer mellan 1-4\n");
            continue;
        }
    }
}