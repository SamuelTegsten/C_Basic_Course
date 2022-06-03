#include <stdio.h>
#include <string.h>
int string_length (int count, char length[]);
int main ()
{
    int count = 0;
    char length[] = "How long is this string?";
    count = string_length(count, length);
    printf("count in string:%d \n", count);
    return 0;
}

    int string_length (int count, char length[])
    {
    while (length[count] != '\0')  
    {
        count++;
    }
    return count;
    }