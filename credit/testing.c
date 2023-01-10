#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Insert credit card number: ");

    int i=0; //Number of digits
    long n = number;
    while(n>=1)
    {
        n= n/10;
        i++;
    }
    n = number;

    int sum1 = 0;
    for (int a=0; a < i-1; a++)
    {
        int d = n%10;
        n = 0.1*(n-d);
        d=n%10;

        if (a%2==0)
        {
        printf("%i", d);
        sum1 += (2*d)%10 + 0.1*((2*d)-((2*d)%10));
        }
    }
    printf("\n%i\n", sum1);
}


