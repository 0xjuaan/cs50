# include <stdio.h>

double fibsum(double *n1, double *n2);



int main(void)
{
    double *n1;
    double *n2;

    *n1 = 1;
    *n2 = 2;

    double n = fibsum(n1, n2);
}

double fibsum(double *n1, double* n2)
{
    return fibsum(n1, n2);
}