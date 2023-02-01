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
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < width; j++) //Iterate horizontally
        {
            if (i = 0)
            {
                if (j = 0)
                {
                    image[i][j].rgbtRed = (image[i+1][j].rgbtRed + image[i][j+1].rgbtRed) / 2;
                    image[i][j].rgbtGreen = (image[i+1][j].rgbtGreen + image[i][j+1].rgbtGreen) / 2;
                    image[i][j].rgbtBlue = (image[i+1][j].rgbtBlue + image[i][j+1].rgbtBlue) / 2;
                }
                else
                {
                    image[i][j].rgbtRed = (image[i+1][j].rgbtRed + image[i][j+1].rgbtRed + ) / 2;
                    image[i][j].rgbtGreen = (image[i+1][j].rgbtGreen + image[i][j+1].rgbtGreen) / 2;
                    image[i][j].rgbtBlue = (image[i+1][j].rgbtBlue + image[i][j+1].rgbtBlue) / 2;
                }
            }

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
