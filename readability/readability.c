#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int sentences, letters = 0;
int words = 1;

int main(void)
{
    string text = get_string("Text: ");

    for (int i=0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i]==33 || text[i]==46 ||text[i]==63)
        {
            sentences++;
        }
    }

    printf("Letters: %i\n", letters);
    printf("Words: %i\n", words);
    printf("Sentences: %i\n", sentences);

    double index = (double) 0.0588 * (100 * letters/ words) - 0.296 * (100 * sentences / words) - 15.8;

    int grade = round(index);

    if (index>=16)
    {
        printf("Grade 16+\n");
    }
    else if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
    printf("Grade %i\n", grade);
    }
}
