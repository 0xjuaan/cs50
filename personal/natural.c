#include <stdio.h>
#include <cs50.h>
int natural(int n);

int main(void)
{
    printf("The natural numbers are: ");
    natural(50);
}


int natural(int n)
{
    if (n == 0)
    {
        return 0;
    }
    natural(n-1);
    printf("%i ", n);
    return 1;
}