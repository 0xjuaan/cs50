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
    int kernelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, -{1, 0, 1}};
    int kernelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //Defining the Gx,Gy
    int Rx=0, Gx=0, Bx=0, Ry=0, Gy=0, By=0;

    //Copying the image to a temp[][]
    RGBTRIPLE temp[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            temp[a][b] = image[a][b];
        }
    }

    for (int i = 0; i < height; i++) //Vertical
    {
        for (int j = 0; j < width; j++) //Horizontal
        {
            //Let Gx,Gy start at 0, before we start adding to it
            Rx = 0;
            Gx = 0;
            Bx = 0;

            Rx = 0;
            Gx = 0;
            Bx = 0;

            int kindex = 0;

            for (int cy = 0; int k = i - 1; k < i + 2; k++; cy++) //3x3 Collumns
            {
                for (int cx = 0; int l = j - 1; l < j + 2; l++; cx++) //3x3 Rows
                {
                    if (l < 0 || l >= width)
                    {
                        continue;
                    }

                    else if (k < 0 || k >= height)
                    {
                        continue;
                    }

                    else
                    {
                        Rx += kernelX[cy][cx] * temp[k][l].rgbtRed;
                        Gx += kernelX[cy][cx] * temp[k][l].rgbtGreen;
                        Bx += kernelX[cy][cx] * temp[k][l].rgbtBlue;

                        Ry += kernelY[cy][cx] * temp[k][l].rgbtRed;
                        Gy += kernelY[cy][cx] * temp[k][l].rgbtGreen;
                        By += kernelY[cy][cx] * temp[k][l].rgbtBlue;

                        kindex++;
                        continue;
                    }
                }
            }
            image[i][j].rgbtRed =   round(sqrt(pow((double) Rx, 2) + pow((double) Ry, 2)));
            image[i][j].rgbtGreen = round(sqrt(pow((double) Gx, 2) + pow((double) Gy, 2)));
            image[i][j].rgbtBlue =  round(sqrt(pow((double) Bx, 2) + pow((double) By, 2)));

            //Capping at 255
            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
        }
    }
    return;
}
