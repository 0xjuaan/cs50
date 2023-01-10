#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long number = get_long("Insert credit card number: ");

    int i = 0; //Number of digits
    long n = number;
    while(n>=1)
    {
        n  = n / 10;
        i++;
    }
    n = number;
    // printf("size = %i\n", i);

    int sum1 = 0;
    int sum2 = 0;
    int d = n % 10;

    for (int a=0; a < i; a++)
    {
        n = 0.1 * (n - d);
        if (a % 2 != 0)
        {

            sum1 += (2*d)%10 + 0.1*((2*d)-((2*d)%10));
        }
        else
        {
            sum2 += d;
        }
        d=n%10;
    }

    if ((sum1 + sum2)%10==0)
    {
       // printf("Approved Checksum g\n");
        if (i==15)
        {
            if (number >= 370000000000000)
            {
                if (number <= 379999999999999)
                {
                    printf("AMEX");
                }
            }
            else if (number >= 340000000000000)
            {
                if (number <= 349999999999999)
                {
                    printf("AMEX");
                }
            }

        }
        else if (i==13 && number <=4999999999999)
        {
            if (number >=4000000000000)
            {
                printf("VISA");
            }

        }
        else if (i==16)
        {
            if (number >=5100000000000000)
            {
                if (number <= 5599999999999999)
                {
                    printf("MASTERCARD");
                }
            }
            else if (number <=4999999999999999)
            {
                if (number >=4000000000000000)
                {
                    printf("VISA");
                }
            }
        }
    }
    else
    {
        printf("INVALID");
    }

}


