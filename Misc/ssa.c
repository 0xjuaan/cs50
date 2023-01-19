# include <stdio.h>
#include <cs50.h>

int main(void)
{
    string strings[2];
    strings[0]= "HI!";
    strings[1]= "BYE!";


    printf("%c%c%c\n", strings[0][0], strings[0][1], strings[0][2]);
    printf("%c%c%c%c\n", strings[1][0], strings[1][1], strings[1][2], strings[1][3]);
}
