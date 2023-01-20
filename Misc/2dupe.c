#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool fd(string s)
{
    bool seen[26];
    for (int i = 0; i < 26; i++)
    {
        if (seen[i - s[i]] == true)
        {
            return true;
        }
        else
        {
            seen[i - s[i]] = true;
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