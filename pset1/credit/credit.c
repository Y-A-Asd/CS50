#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int dig(long numb);

int main(void)
{
    int mas[] = {51, 52, 53, 54, 55};
    long y = 0;
    long n = get_long("Number: "); //card number
    const long n1 = n;
    int num = dig(n);;
    for (int i = 0; i < num; i += 2)
    {
        n = n1 / pow(10, i);
        y += n % 10;
    }
    n = n1;
    for (int j = 1; j < num; j += 2)
    {
        n = n1 / pow(10, j);
        if (n % 10 * 2 > 9)
        {
            y += (n % 10 * 2 % 10) + 1;
        }
        else
        {
            y += n % 10 * 2;
        }
    }
    if (y % 10 == 0)
    {
        if (n1 / 10000000000000 == 37 || n1 / 10000000000000 == 34)//AMEX
        {
            printf("AMEX\n");
        }
        else if (n1 / 100000000000000 == mas[0] || n1 / 100000000000000 == mas[1] || n1 / 100000000000000 == mas[2]
                 || n1 / 100000000000000 == mas[3] || n1 / 100000000000000 == mas[4])//MASTERCARD
        {
            printf("MASTERCARD\n");
        }

        else if (n1 / 1000000000000000 == 4 || n1 / 1000000000000 == 4)//VISA
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int dig(long numb)
{
    for (int i = 0; i < 50; i++)
    {
        long a = pow(10, i);
        long b = (long)numb / pow(10, i);
        //printf("%ld\n", a);
        //printf("%ld\n", b);
        if (b < 1)
        {
            return i;
        }
    }
    return 0;
}
//Yousof.A.Asadi(Y.A.A)8/15/2021

