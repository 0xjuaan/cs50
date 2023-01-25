#include <stdio.h>
#include <cs50.h>
bool bsearch (int array[], int size_, int search_);


int main(void)
{
    int numbers[] = {1, 4, 7, 9, 16, 56, 70};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int search = get_int("Search for: ");
}


bool bsearch (int array[], int size_, int search_)
{
    if (numbers[size_  / 2 - 1] == search_)
    {
        printf("Found!");
    }
    else if (numbers[size_  / 2 - 1] >= search_)
    {
        bsearch(numbers, size/2 - 1, search)
    }
}