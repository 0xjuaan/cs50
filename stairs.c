#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

void draw(int height);
void drraw(int height, int i);

int main(void)
{
    int height = get_int("Height: ");
    drraw(height,1);
}
void draw(int height)
{
for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }
            printf("\n");
    }
}

void drraw(int height, int i)
{
    for (i = 0; i < height; i++)
    {
        printf("#");
        drraw(height, i+1);
    }

}