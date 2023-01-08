#include <cs50.h>
#include <stdio.h>


//Pseudocode
//Print 1, break 1, Print 1
//
int main(void)
{
    int height;
    do
    {
        height = get_int("What is the pyramid size? ");
    }
    while (height<1 || height>8);

    int n=0;
    for (n=0;n<2;n++)
    {
        printf("#");
        printf(" ");
        printf("#");
    }

}