#include <cs50.h>
#include <stdio.h>


//Pseudocode
//Let n=1
//Print 1
""
bee

""



int main(void)
{
    int height;
    do
    {
        height = get_int("What is the pyramid size? ");
    }
    while (height<1 || height>8);

    int n=1;
    for (int a=0; a<2; a++)
    {
        for (int i=0; i<n; i++)
        {
            printf("#");
        }
        printf(" ");
    }
}