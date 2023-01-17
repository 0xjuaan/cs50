#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool wemadeit;
bool argcheck(string key, int argc, string alphabet);


int main(int argc, string argv[])
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz"
}

 bool argcheck(string key, int argc, string alphabet)
{
    int c = 0;

    if (argc==2)
    {
        if (strlen(key)==26)
        {
            wemadeit = true;
            for (int a = 0; a < 26; a++)
            {
                for (int b = 0; b < 26; b++)
                {
                    if (key[a] == alphabet[b])
                    {
                        c++;
                        break;
                        printf("%i", c);
                    }
                    else
                    {
                        continue;
                    }
                }
                break;
            }
            if (c == 26)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }



}
