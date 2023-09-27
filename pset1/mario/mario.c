#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n; //number
    int b; //line
    int c; //space
    int e; //#
    do
    {
        n = get_int("Height:  ");
    }
    while (n < 1 || n > 8);

    for (b = 0; b < n; b++)  //line
    {
        for (c = n - (1 + b); c > 0; c--)  //space
        {
            printf(" ");
        }
        for (e = 0; e < b + 1; e++)  //#
        {
            printf("#");
        }
        printf("\n");
    }
}

