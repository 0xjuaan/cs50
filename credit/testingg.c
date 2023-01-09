#include <cs50.h>
#include <stdio.h>

int main(void)
{
long number = 378282246310525;

long ting = number - number%10;

printf("%li\n", ting);

}