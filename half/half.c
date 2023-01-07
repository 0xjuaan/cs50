// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill = get_float("Bill before tax and tip: ");
    float tax = get_float("Sale Tax Percent: ");
    int tip = get_int("Tip percent: ");

    printf("You will owe $%s each!\n", half(float bill, float tax, int tip));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float n;
  n =   bill*(1/2 + tax*0.01 + tip*0.01);
  return n;
}

