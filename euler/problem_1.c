# include <stdio.h>

int main(void)
{
    int n = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            n += i;
        }
    }
    printf("%i\n", n);
}