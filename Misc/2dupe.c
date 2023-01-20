#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool fd(string s)
{
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (seen[s[i]-'A'] == true) // This converts the string value into the int i
        {
            return true;
        }
        else
        {
            seen[s[i]-'A'] = true;
            continue;
        }
    }
    return false;
}

int main(void)
{

    string sub = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (fd(sub))
    {
        printf("Dupe\n");
    }
    else
    {
        printf("Clean\n");
    }
}