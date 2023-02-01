#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < height; j++) //Iterate horizontally
        {
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j].rgbtRed = 66;
                image[i][j].rgbtGreen = 231;
                image[i][j].rgbtBlue = 215;
            }
        }
    }
}
