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
    

}

