#include <cs50.h>
#include <stdio.h>


//Pseudocode
//Let n=1
//Print 1

int main(void)
{
    int height;
    do
    {
        height = get_int("What is the pyramid size? ");
    }
    while (height<1 || height>8);

    int n=1;
    while(n<=height)
    {
        for(int j=0; j<(height-n); j++)
                {
                    printf(" ");
                }
        for (int a=0; a<2; a++) //REPEATS THE RATATA TWICE!!
        {
            for (int i=0; i<n; i++)
            {
                
                printf("#"); //RATATATA!!
            }
            if (a==0)
            {
                printf("  ");
            }
        }

        n++;
        printf("\n");
    }
}