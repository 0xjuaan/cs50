// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
char replace(string array[1]);


int main(int argc, string argv[])
{
do
{
    replace(argv);
}
while (argc != 2);
}

char replace(string array[1])
{
    for (int i=0; i<strlen(array[1]); i++)
    {
        switch (array[1][i])
        {
            case array[1][i] == 'a':
                printf(6);
                break;

            case array[1][i] == 'e':
                printf(3);
                break;

            case array[1][i] == 'i':
                printf(1);
                break;

            case array[1][i] == 'o':
                printf(0);
                break;

            case array[1][i]:
                printf("%c", array[1][i]);
                break;
        }
    }
}
