# include <stdio.h>
#include <stdlib.h>

double fibsum(double *n, double *nn);



int main(void)
{
    double *n1 = malloc(sizeof(double));
    double *n2 = malloc(sizeof(double));

    *n1 = 1;
    *n2 = 2;

    double n = fibsum(n1, n2);
    printf("%f", n);
}

double fibsum(double *n, double* nn)
{
    if (*nn >= 4000000)
    {
        return 0;
    }
    return fibsum(n, nn);
}