#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sub      = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int array[26];

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
        if (sub[i]==sub[j])
        {
            printf("Dupe\n");
            return 1;
        }
        else
        {
            continue;
        }
        }
    }
    printf("clean\n");

}