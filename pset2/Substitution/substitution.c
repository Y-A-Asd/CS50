#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{


    char alph[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int count = 1;
    if (argc == 2)
    {
        int n = strlen(argv[1]);

        if (n == 26)
        {
            for (int i = 0; i < n; i++)
            {
                for (int v = 0; v < n; v++)
                {
                    //find same latter
                    for (int j = v + 1; j < n; j++)
                    {
                        if (toupper(argv[1][v]) == toupper(argv[1][j]))
                        {
                            count++;
                            argv[1][j] = '0';
                        }
                    }
                    if (count > 1 && argv[1][v] != '0')
                    {
                        printf("Key must not contain repeated characters\n");
                        return 1;
                    }
                }
                //Check for alphabetical
                for (int k = 0; k < n; k++)
                {
                    if (isalpha(argv[1][k]))
                    {
                    }
                    else
                    {

                        printf("Key most only contain alphabetic characters.\n");

                        return 1;
                    }
                }
                // main substitution
                string input = get_string("plaintext: ");

                printf("ciphertext: ");

                int d = strlen(input);

                for (int t = 0; t < d; t++)
                {
                    int y = 0;
                    int z = 0;
                    if (isalpha(input[t]))
                    {
                        if (islower(input[t]))
                        {
                            while (input[t] != alph[y])
                            {
                                y++;
                            }
                            printf("%c", tolower(argv[1][y]));
                        }
                        else if (isupper(input[t]))
                        {
                            while (input[t] != toupper(alph[z]))
                            {
                                z++;
                            }
                            printf("%c", toupper(argv[1][z]));

                        }
                    }
                    else
                    {
                        printf("%c", input[t]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
        else
        {
            //Check for number of letter
            printf("Key most contain 26 characters.\n");
            return 1;
        }
    }
    else if (argc != 2)
    {
        //Check for key
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}
//Yousof.A.Asadi(Y.A.A)8/8/2021