#include <cs50.h>
#include <stdio.h>

int main(void)
{
long number = 378282246310505;
long d1 = number % 10;
printf("First digit: %li\n", d1);
long d2 = (long)(0.1*(number-d1)) % 10;
printf("Second digit: %li\n", d2);
long d3 = (long) 0.1*(0.1*(number-d1)-d2) % 10;
printf("Third digit: %li\n", d3);


for (i=0; i<16, i++)
{
    
}

}
