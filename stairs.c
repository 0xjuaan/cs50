#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    int height = get_int("Height: ");
    for (int i = 0; i < height + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
            printf("\n");

    }
}