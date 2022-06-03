    #include<stdio.h>  
    int main()    
    {    
        double i, factorial=1, longdouble1;   

        printf("Enter a number: ");    
        scanf("%lf",&longdouble1);    
        
        for(i=1.0f; i<=longdouble1; i++)

        {    
            factorial = factorial*i;    
        }    

        printf("Factorial of %.1f: %f",longdouble1,factorial);  

        return 0;  
    }   