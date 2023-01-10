#include <cs50.h>
#include <stdio.h>

int checksum(long number);

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
    checksum(number);

}

int checksum(long number)
{
    long n = number
    int d = n % 10;
    for (a=0; a<i; a++)
    {
        n = 0.1*(n-d);
        d=n%10;

        if (a%2>0)
        {
        printf("d");
        }
    }
}

