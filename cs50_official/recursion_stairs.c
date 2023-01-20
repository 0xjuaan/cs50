// Draws a pyramid using recursion 2
 #include <cs50.h>
 #include <stdio.h>

void draw(int n);

int main(void)
{

int height = get_int("Height: ");

draw(height);
}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
    return;
    }
        // Draw pyramid of height == (n - 1)
    draw(n - 1);
        // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
time ./sort1 sort