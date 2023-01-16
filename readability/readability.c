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
        else
        {
            continue;
        }
    }

        double L = (letters / words) * 100.000;
        double S = (sentences / words) * 100.000;
        double index = 0.0588 * L - 0.296 * S - 15.8;

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
