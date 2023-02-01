#include "helpers.h"
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < width/2; j++) //Iterate horizontally
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width-j];
            image[i][width-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
