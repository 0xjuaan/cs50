#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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


}