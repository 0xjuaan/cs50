
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string n);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string s)
{

if (strlen(s) == 0)
{
    return 0;
}

int a = s[strlen(s)-1]-'0'; //Subracting ASCII '0' OR 48 is the same thing.
s[strlen(s)-1] = '\0'; //Practically shortening the string from the right-end
return a + 10 * convert(s); //Return the last digit + 10*(next digit)
}



/*
Pseudocode

input = 123;

int n = (s[2]-48) + 10*(s[2-1]-48) + 10*10*(s[2-1-1]-48)



*/