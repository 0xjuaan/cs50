#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for (int i = 0; i < height; i++) //Iterate vertically
    {
        for (int j = 0; j < height; j++) //Iterate horizontally
        {
            if (image[i][j] == 0)
            {
                image[i][j].Red = 66;
                image[i][j].Green = ;
                image[i][j].Blue = ;

            }
        }
    }
}
