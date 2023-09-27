// Modifies the volume of an audio file
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>


// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t HEAD;
HEAD head[HEADER_SIZE];
typedef int16_t SEMP;
SEMP semp;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    fread(&head, sizeof(head), 1, input);

    fwrite(&head, sizeof(head), 1, output);


    while (fread(&semp, sizeof(semp), 1, input))
    {
        semp = semp * factor;
        fwrite(&semp, sizeof(semp), 1, output);
    }




    // Close files
    fclose(input);
    fclose(output);
}
//Yousof.A.Asadi(Y.A.A)5/24/2023