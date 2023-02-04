#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < width; j++) //Iterate horizontally
        {
            int avg = round(( (float) image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < width/2; j++) //Iterate horizontally
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width-1)-j];
            image[i][(width-1)-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int a = 0; a < height; a++) //Copying the image to a temp
    {
        for (int b = 0; b < width; b++)
        {
            temp[a][b] = image[a][b];
        }
    }

    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < width; j++) //Iterate horizontally
        {
            int sumr = 0;
            int sumg = 0;
            int sumb = 0;
            int n = 0;

            for (int k = i-1; k < i+2; k++) //vertical iteration of 3x3
            {
                for (int l = j-1; l < j+2; l++) //horizontal iteration of 3x3
                {
                    if (l < 0 || l >= width)
                    {
                        continue;
                    }
                    else if (k < 0 || k >= height)
                    {
                        continue;
                    }
                    sumr += temp[k][l].rgbtRed;
                    sumg += temp[k][l].rgbtGreen;
                    sumb += temp[k][l].rgbtBlue;
                    n++;
                }
            }

            image[i][j].rgbtRed = round((float) sumr / n);
            image[i][j].rgbtGreen = round((float) sumg / n);
            image[i][j].rgbtBlue = round((float) sumb / n);

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Defining the kernels (3x3)
    int kernelX[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1}
    int kernelY[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1}

    //Defining the Gx,Gy
    RGBTRIPLE Gx;
    RGBTRIPLE Gy;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            
        }
    }
    return;
}
