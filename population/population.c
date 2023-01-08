#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int initial;
    do
    {
 initial = get_int("What is the starting population size? ");
    }
    while (initial<9);
    // TODO: Prompt for end size
    int final;
do
    {
 final = get_int("What is the final population size? ");
    }
    while (final<=initial);
    // TODO: Calculate number of years until we reach threshold ( in 't' years)
int t = 0;
while (initial<final)
    {
        initial += (float) initial/12;
        t++;
        printf("Population after %i year(s) is %i\n", t, initial);

    }
    printf("Years: %i\n", t-1);
}