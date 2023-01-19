 #include <cs50.h>
 #include <stdio.h>

void draw(int n);

int main(void)
{

int number = get_int("Number: ");

factorial(number);


}


void factorial(n)
{
    if (n <=0)
    {
        return;
    }
    factorial(n-1)

    n*(n-1);
}