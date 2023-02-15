#include <stdio.h>

int main(void)
{
    FILE *file = fopen("dictionaries/large", "r");
    if (file != NULL)
    {
        char ch;
        int counter = 0;
        while ((ch = fgetc(file)) != EOF)
        {
            if (ch == '\n')
            {
                counter++;
            }
        }

        fclose(file);
        printf("%i\n", counter);
    }
}