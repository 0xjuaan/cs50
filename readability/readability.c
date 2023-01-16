#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int sentences, words, letters = 0;

int main(void)
{
    string text = get_string("Text: ");

    for (int i=0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            continue;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i]=)
    }


}