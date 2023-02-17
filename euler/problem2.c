# include <stdio.h>

double fibsum(double *1st, double *2nd);



int main(void)
{
    double *n1;
    double *n2;

    *n1 = 1;
    *n2 = 2;

    double n = fibsum(n1, n2);
}

double fibsum(double *1st, double* 2nd)
{
    return fibsum(1st, 2nd);
}