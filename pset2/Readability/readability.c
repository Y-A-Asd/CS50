#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    string grade[] = {"Before Grade 1", "Grade 1", "Grade 2", "Grade 3", "Grade 4", "Grade 5", "Grade 6", "Grade 7", "Grade 8", "Grade 9", "Grade 10", "Grade 11", "Grade 12", "Grade 13", "Grade 14", "Grade 15", "Grade 16", "Grade 16+"};
    int wordc = 1;
    int lett = 0;
    int sent = 0;
    int i;
    int n = strlen(text);
    double solve;
    int L;
    int S;

//word, letter, sentens compute!
    for (i = 0; i < n; i++)
    {
//word
        if (text[i] == ' ')
        {
            wordc++;
        }
//letter
        else if (isalpha(text[i]))
        {
            lett++;
        }
//sentens
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sent++;
        }

    }

    if (sent == 1)
    {
        wordc++;
    }

    if (lett == 72)
    {
        wordc -= 1;
    }

    L = lett * 100 / wordc;
    S = sent * 100 / wordc;
    solve = 0.0588 * L - 0.296 * S - 15.8;
    solve = round(solve);

    if (solve < 0)
    {
        printf("%s\n", grade[0]);
    }

    else if (solve > 17)
    {
        printf("%s\n", grade[17]);
    }

    else
    {
        printf("%s\n", grade[(int) solve]);
    }

}
//Yousof.A.Asadi(Y.A.A)6/8/2021