#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#include <math.h>
int enter(int loading_array[], int number_of_elements);
int view(int loading_array[], int number_of_elements);
int calculate_max(int loading_array[], int number_of_elements);
int calculate_min(int loading_array[], int number_of_elements);
float calculate_average(int loading_array[], int number_of_elements);
int calculate_normalised(int normalised_array[], int loading_array[], int number_of_elements);
int main ()
{
    int number_of_elements = 0;
    int loading_array[10];
    int normalised_array[10];
    printf("Measurement tool 2.0 \n");
    for(int i = 0; i < i + 1; i++)
    {
        char tmp;
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");
        scanf(" %c", &tmp);
        
        if(tmp == 'e') // ENTER
        {
            number_of_elements = enter(loading_array, number_of_elements);
        }
        if(tmp == 'v') // VIEW
        {
            view(loading_array, number_of_elements);
        }
        if(tmp == 'c') // COMPUTE
        {
        int max = calculate_max(loading_array,number_of_elements);
        if(number_of_elements == 0)
        {
            printf("No meassurements \n");
            continue;
        }
            else
        {
                printf("Max value: %d\n", max);
        }
        int min = calculate_min(loading_array,number_of_elements);
        printf("Min value: %d\n", min);
        float average = calculate_average(loading_array,number_of_elements);
        printf("Average Value: %.2f \n", average);
        calculate_normalised(normalised_array,loading_array,number_of_elements);
        printf(" [");
        for(int i = 0 ; i < number_of_elements ; i++) 
        {
            printf("%d ",normalised_array[i]);
        }
        printf("] \n");
        }
        if(tmp == 'r') // RESET
        {
            printf("Resetting Elements in the Array \n");
            number_of_elements = 0;
        }
        if(tmp == 'q') // QUIT
        {
            printf("Exiting Program");
            break;
        }
    }

    return 0;
}

    int enter(int loading_array[], int number_of_elements)
    {
        int oneMeasurement;
        for(number_of_elements; number_of_elements < 10; number_of_elements++)
        {
            printf("Enter measurement #%d (or q to quit): ", number_of_elements + 1);
            int readInterger = scanf("%d", &oneMeasurement);
            if(readInterger)
            {
                loading_array[number_of_elements] = oneMeasurement;
            }
            else 
            {
                char tmp;
                scanf(" %c", &tmp); 
                return number_of_elements;
            }
        }  
    }   
    int view(int loading_array[], int number_of_elements)
    {
        if(number_of_elements == 0)
        {
            printf("No meassurements ");
        }
        if(number_of_elements > 0)
        {
        printf("[ ");
        }
        for(int i = 0; i < number_of_elements; i++)
        {
            if(number_of_elements == 0)
        {
                continue;
        }
            printf("%d ", loading_array[i]);
        }
        if(number_of_elements > 0)
        {
        printf("] ");
        }   
        printf("\n");
    }
    int calculate_max(int loading_array[], int number_of_elements)
    {
        int max = loading_array[0];
        for(int i = 0; i < number_of_elements; i++)
        {
            if(max < loading_array[i])
            {
                max = loading_array[i];
            }
        }
    return max;
    }
    int calculate_min(int loading_array[], int number_of_elements)
    {
        int min = loading_array[0];
        for(int i = 0; i < number_of_elements; i++)
        {
            if(min > loading_array[i])
            {
                min = loading_array[i];
            }
        }
    return min;
    }
    float calculate_average(int loading_array[], int number_of_elements)
    {
        float average = 0;
        int i;
        for(i = 0; i < number_of_elements; i++)
        {
            average = average + loading_array[i];
        }
        float sum = average / number_of_elements;
    return sum;
    }
    int calculate_normalised(int normalised_array[], int loading_array[], int number_of_elements)
    {
        float average = 0;
        int i;
        for(i = 0; i < number_of_elements; i++)
        {
            average = average + loading_array[i];
        }
        float sum = average / number_of_elements;
        sum = round(sum);
        for(i = 0; i < number_of_elements; i++)
        {
            normalised_array[i] = loading_array[i] - sum;
        }
    }