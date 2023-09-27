#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int s;
    int e;
    int n = 0;

    do
    {
        s = get_int("Early population: ");
    }
    while (s < 9);

    do
    {
        e = get_int("Final population: ");
    }
    while (e < s);

    if (s != e)
    {
        while (s < e)
        {
            s = s + (s / 3) - (s / 4);
            n++;
        }
        printf("Years: %i\n", n);
    }
    else
    {
        n = 0;
        printf("Years: %i\n", n);
    }



}