 #include <cs50.h>
 #include <stdio.h>

void factorial(int n);

int main(void)
{

int number = get_int("Number: ");

factorial(number);


}


void factorial(int n)
{
    if (n = 1)
    {
        return;
    }
    n * factorial(n-1)

}