#include <stdio.h>

int main(void)
{
    FILE *file = fopen("dictionaries/large", "r");
    if (file != NULL)
    {
        char buffer[10];
        while ((ch = fgetc(dict))

        fclose(file);
        printf("%s\n", buffer);
    }
}