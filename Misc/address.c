#include <stdio.h>
#include <cs50.h>
#include<stdlib.h>

int main(void)
{
    int *x = malloc(5*sizeof(int));
    x[0] = 4;
    x[1]= 5;
    printf("%i\n", *(x+1));
}