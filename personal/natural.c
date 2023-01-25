#include <stdio.h>
#include <cs50.h>
int natural(int n);

int main(void)
{
    printf("%i\n", natural(5));

}


int natural(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return natural(n-1);
}