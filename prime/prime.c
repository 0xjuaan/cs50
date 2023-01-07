#include <cs50.h>
#include <stdio.h>

//Pre-defining the function for the compiler
bool prime(int i);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i: prime\n", i);
        }

    }
}

bool prime(int i)
{
    // TODO
    for (int d=2; d<i; d++)
    {
        if (i % d == 0 && i != d)
        {
            return 0;
        }


        else if (i % d !=0 && d==i-1)
        {
            return 1;
        }
        else if ()
    }
    return 0;
}