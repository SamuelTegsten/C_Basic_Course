#include <stdio.h>
int main ()
{
    float time, throttle, height, velocity, fuel;

    printf("Lunar decent challange\n");
    printf("You will each pilot a lunar decent the last 250m.\n");
    printf("Each turn will represent 1-second decent time\n");
    printf("Set the throttle each turn (0-100)\n");

    height = 250.0f;
    velocity = -25.0f;
    fuel = 500.0f;

    printf("Time\tHeight\tVelocity\tFuel\tThrottle?\t\n");

    for(time = 0.0f; height > 0.0f ;time++)
    {
        printf(" %.1f     %.1f   %.1f          %.1f       ", time, height, velocity, fuel);
        scanf("%f", &throttle);   

        if(throttle > 100)

        {
            printf("Error, please enter a valid throttle (0-100), ending program\n");
            break;
        }

        if(fuel <= 0)
        {
            fuel = 0;
            throttle = 0;
        }

        height = (height + velocity) + (0.1f * throttle - 1.5f) / 2.0f;
        velocity = velocity + (0.1f * throttle - 1.5f);
        fuel = fuel - throttle;

        

    }
        if (height <= 0.0f && velocity < -2.0f)
        {
            printf("FAILED, crash landing at: %f m/s\n", velocity);
        }
        else if (height <= 0.0f && velocity > -2.0f)
        {
            printf("SUCCES, landing at: %f m/s\n", velocity);
        }

    return 0;
}