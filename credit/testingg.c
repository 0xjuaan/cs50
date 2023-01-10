#include <cs50.h>
#include <stdio.h>

int main(void)
{
 int d =6;
 int sum1 = (2*d)%10 + 0.1*((2*d)-((2*d)%10));
 printf("%i\n", sum1);
}