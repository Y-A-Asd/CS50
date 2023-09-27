#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float SUMA = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0;
            int sum = round(SUMA);
            image[i][j].rgbtRed = sum;
            image[i][j].rgbtBlue = sum;
            image[i][j].rgbtGreen = sum;
        }
    }
    return;
}
//if image[i][j] > 255
int max(int color)
{
    if (color > 255)
    {
        color = 255;
    }
    return color;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int bluee = max(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            int greenn = max(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            int redd = max(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            image[i][j].rgbtBlue = bluee;
            image[i][j].rgbtGreen = greenn;
            image[i][j].rgbtRed = redd;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE swap = image[i][j];
            image[i][j] = image[i][width - (1 + j)];
            image[i][width - (1 + j)] = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])

{
    RGBTRIPLE swap[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float redd = 0;
            float bluee = 0;
            float greenn = 0;
            float sol;
            sol = 0;
            for (int c = -1; c < 2; c++)
            {
                for (int d = -1; d < 2; d++)
                {
                    if (i + c < 0 || i + c > height - 1)
                    {
                        continue;
                    }

                    if (j + d < 0 || j + d > width - 1)
                    {
                        continue;
                    }

                    bluee += image[i + c][j + d].rgbtBlue;
                    greenn += image[i + c][j + d].rgbtGreen;
                    redd += image[i + c][j + d].rgbtRed;
                    sol++;
                }
            }

            swap[i][j].rgbtBlue = round(bluee / sol);
            swap[i][j].rgbtGreen = round(greenn / sol);
            swap[i][j].rgbtRed = round(redd / sol);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = swap[i][j].rgbtBlue;
            image[i][j].rgbtGreen = swap[i][j].rgbtGreen;
            image[i][j].rgbtRed = swap[i][j].rgbtRed;
        }

    }

    return;
}
//Yousof.A.Asadi(Y.A.A)5/24/2023