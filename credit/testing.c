#include <cs50.h>
#include <stdio.h>

int main(void)
{
long number = 378282246310005;
long d1 = number % 10;
printf("First digit: %li\n", d1);
long d2 = (number-d1) % 10;
printf("Second digit: %li\n", d2);
long d3 = (number-d1-d2) % 10;
printf("Second digit: %li\n", d2);

}
