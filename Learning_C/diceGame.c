#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#include <math.h>

int roll_dice ();
int play_game();

int main ()
{
    int win;
    int lose;
    char yes_or_no;
    int n_of_wins = 0;
    int n_of_losses = 0;
    int w = 0;
    int l = 0;
    for(int i = 0; i < i + 1; i++)
    {  
        play_game();
        win = play_game();
        lose = play_game();
        if(lose == 0)
        {
            printf("You lose! \n");
            printf("Play again? y for yes, n for no \n");
            l = l + 1;
            n_of_losses = l;
            scanf(" %c", &yes_or_no);
            if(yes_or_no == 121)
            {
                continue;
            }
            else if(yes_or_no == 110)
            {
                printf("Wins:%d Losses:%d ", n_of_wins, n_of_losses);
                break;
            }
        }
        else if (win == 1)
        {
            printf("You win! \n");
            printf("Play again? y for yes, n for no \n");
            w = w + 1;
            n_of_wins = w;
            scanf(" %c", &yes_or_no);
            if(yes_or_no == 121)
            {
                continue;
            }
            else if(yes_or_no == 110)
            {
                printf("Wins:%d Losses:%d ", n_of_wins, n_of_losses);
                break;
            }
        }
    }
return 0;
}

int roll_dice ()
{
    int i;
    int sum;
    int roll1;
    int roll_two;
    for(i = 0; i <= 1; i++)
    {
    srand(time(NULL));
    roll1 = rand () % 6 + 1;
    roll_two = rand () % 6 + 1;
    sum = roll1 + roll_two;
    }
    return sum;
}

int play_game()
{   
    int sum = roll_dice();
    if(sum == 7 || sum == 11)
    {
        return 1;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        return 0;
    }
    else if (sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10);
    {
    printf("You rolled %d \n", sum);
    printf("Your point is %d \n", sum);
    int sum1;
    sum = sum1;
    int roll2;
    roll2 = roll_dice();
    if(roll2 == 7)
    {
        return 0;
    }
    if(roll2 == sum1)
    {
        return 1;
    } 
    else if(roll2 == 2 || roll2 == 3 || roll2 == 4 || roll2 == 5 || roll2 == 6 || roll2 == 8 || roll2 == 9 || roll2 == 10 || roll2 == 11 || roll2 == 12)
    {
        for(int i = 0; i < i + 1; i++)
        {
            int role_end = roll_dice();
            if (role_end == 7)
            {
                printf("You rolled %d\n" , sum);
                return 0;
                break;
            }
            else if (role_end == sum1)
            {
                printf("You rolled %d\n" , sum);
                return 1;
                break;
            }
            else
            printf("You rolled %d \n", role_end);
        }
    }
    }
    }