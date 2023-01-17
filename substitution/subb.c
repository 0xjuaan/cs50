#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool wemadeit;
bool argcheck(string argv[], int argc);
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    if (argcheck(argv, argc)==true)
    {
        printf("true\n");
    }
    else
    {
        printf("false");
    }
}

bool argcheck(string argv[], int argc)
{
    int c = 0;
    if (argc!=2)
    {
        return false;
    }
    else if (strlen(argv[1])!=26)
    {
        return false;
    }
    for (int a = 0; a < 26; a++)
    {
        for (int b = 0; b < 26; b++)
        {
            if (argv[1][a] == alphabet[b])
            {
                c++;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    if (c==26)
    {
        return true;
    }
    else
    {
        return false;
    }
}
