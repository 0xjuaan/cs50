#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Insert credit card number: ");
    if (number<3400000000000)
    {
        printf("INVALID");
    }
}