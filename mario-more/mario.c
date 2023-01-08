#include <cs50.h>
#include <stdio.h>


//Pseudocode
//
int main(void)
{
    int height;
    do
    {
        height = get_int("What is the pyramid size? ");
    }
    while (height<1 || height>8);

}