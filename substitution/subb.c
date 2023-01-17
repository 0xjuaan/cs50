#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool wemadeit;
bool argcheck(string argv[], int argc, string alphabet);


int main(int argc, string argv[])
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    argcheck(argv[], argc, alphabet);

    if (argcheck(argv[], argc, alphabet)==true)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}

bool argcheck(string argv[], int argc, string alphabet)
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
