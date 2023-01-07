#include <cs50.h>
#include <stdio.h>

int main(void)
{

char choice = get_char("Do you agree to the terms and conditions? ");

if (choice == 'y' || choice =='Y')
{
    printf("good\n");
}
else if (choice == 'n'|| choice =='N')
{
    printf("well u cant use the service then m8\n");
}
else
{
     printf("either 'y' or 'n' fam\n");
}






}