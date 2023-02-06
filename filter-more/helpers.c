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

    typedef struct
    {
        double red;
        double green;
        double blue;
    }
    C;

    C Gx;
    C Gy;
    //Defining the 2 kernels as 1D arrays
    int kernelX[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int kernelY[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    //Copying the image to a temp[][]
    RGBTRIPLE temp[height][width];
    for (int a = 0; a < height; a++)
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
            //Initialise the Gx,Gy to be zero
            Gx.red = 0;
            Gx.green = 0;
            Gx.blue = 0;

            Gy.red = 0;
            Gy.green = 0;
            Gy.blue = 0;

            //Kernel index counter
            int n = 0;

            for (int k = i-1; k < i+2; k++) //vertical iteration of 3x3
            {
                for (int l = j-1; l < j+2; l++) //horizontal iteration of 3x3
                {
                    if (l < 0 || l >= width || k < 0 || k >= height) //Check if out of bounds
                    {
                        n++;
                        continue;
                    }
                    //If not out of bounds:
                    Gx.red += kernelX[n] * temp[k][l].rgbtRed;
                    Gx.green += kernelX[n] * temp[k][l].rgbtGreen;
                    Gx.blue += kernelX[n] * temp[k][l].rgbtBlue;

                    Gy.red += kernelY[n] * temp[k][l].rgbtRed;
                    Gy.green += kernelY[n] * temp[k][l].rgbtGreen;
                    Gy.blue += kernelY[n] * temp[k][l].rgbtBlue;
                    n++;

                }
            }

            image[i][j].rgbtRed = round(sqrt(pow((double) Gx.red, 2) + pow(Gy.red, 2)));
            image[i][j].rgbtGreen = round(sqrt(pow((double) Gx.green, 2) + pow(Gy.green, 2)));
            image[i][j].rgbtBlue = round(sqrt(pow((double) Gx.blue, 2) + pow(Gy.blue, 2)));

            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                continue;
            }
        }
    }
    return;
}
