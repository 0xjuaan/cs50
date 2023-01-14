#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");

    int n=0;

    while (name[n] != 0)
    {
        n++;
    }
    printf("%i\n", n);
}