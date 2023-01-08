#include <cs50.h>
#include <stdio.h>

bool prime(int n);

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

    for (int n = min; n <= max; n++)
    {
        if (prime(n))
        {
            printf("%i\n", n);
        }
    }
}

bool prime(int n)
{
    // TODO
    for (int d = 1; d<n; d++)
    {
    if ( n % d ==0)
        {
            break;
        }

    else if (n%d != 0 && d==n-1)
    {
        return 1;
    }
    else if (n % d != 0)
    {
        continue;
    }

    }
    return false;
}
