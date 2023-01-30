#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    string s = "shush";
    int *t = &s;
    printf("%p\n", t);
    return 0;
}