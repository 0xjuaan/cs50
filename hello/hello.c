#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting user input (name)
    string name = get_string("What's your name? ");
    //Printing that name that was given
    printf("hello, %s\n", name);
}