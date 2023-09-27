#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t byte;


int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover forensicfilename.raw\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 2;
    }

    FILE *IMG;
    int num = 0;
    bool fimg = false;
    byte buff[512];


    while (fread(buff, sizeof(buff), 1, file) == 1)
    {
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            char name[8];
            sprintf(name, "%03.3i.jpg", num);

            if (fimg == true)
            {
                fclose(IMG);
            }

            else
            {
                fimg = true;
            }
            IMG = fopen(name, "w");
            fwrite(buff, sizeof(buff), 1, IMG);
            num++;
        }

        else
        {
            if (fimg == true)
            {
                fwrite(buff, sizeof(buff), 1, IMG);
            }
        }
    }
    fclose(file);
    fclose(IMG);

}
//Yousof.A.Asadi(Y.A.A)5/23/2023