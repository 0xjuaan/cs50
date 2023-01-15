// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
char replace(string argv[1]);


int main(int argc, string argv[])
{
do
{
    replace(argv[1])
}
while (argc != 2)
}

char replace(string argv[1])
{
    for (int i=0; i<strlen(argv[1]); i++)
    {
        switch (argv[1][i])
        {
            case argv[1][i] == 'a':
                printf(6);
                break;

            case argv[1][i] == 'e':
                printf(3);
                break;

            case argv[1][i] == 'i':
                printf(1);
                break;

            case argv[1][i] == 'o':
                printf(0);
                break;

            case argv[1][i]:
                printf("%c", argv[1][i]);
                break;
        }
    }
}
