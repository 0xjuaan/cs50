#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    string s = "shush";
    string *t = &s;
    printf("%p\n", t);
    return 0;
}