#include <stdio.h>
#include <cs50.h>
bool bsearch (int array[], int size, int search);


int main(void)
{
    int numbers[] = {1, 4, 7, 9, 16, 56, 70};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int search = get_int("Search for: ");
}


bool bsearch (int array[], int size, int search)
{
    if (numbers[size_  / 2 - 1] == search)
    {
        printf("Found!");
    }
    else if (numbers[size  / 2 - 1] > search)
    {
        for (int i = 0; i < size  / 2 - 1; i++)
        {
            numbers[i] = '\0';
        }
        bsearch(numbers, size/2 - 1, search)
    }
    else
    {

        bsearch(numbers,, search)
    }
}