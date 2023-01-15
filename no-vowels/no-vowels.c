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
    printf("Usage: ./no-vowels word\n");
}
while (argc != 2);

replace (argv);
}

char replace(string array[1])
{
    for (int i=0; i<strlen(array[1]); i++)
    {
        switch (array[1][i])
        {
            case 97:
                printf("6");
                break;

            case 101:
                printf("3");
                break;

            case 105:
                printf("1");
                break;

            case 111:
                printf("0");
                break;

            printf("%c", array[1][i]);
        }
    }
}
