#include <stdio.h>
#include <cs50.h>
bool bsearch (int array[], int size, int search);

int numbers[] = {1, 4, 7, 9, 16, 56, 70};
int size = sizeof(numbers) / sizeof(numbers[0]);

int main(void)
{

    int search = get_int("Search for: ");

    if (bsearch(numbers, size, search))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found!\n");
    }
}


bool bsearch (int array[], int size_, int search_)
{
    if (numbers[size/2] == search_)
    {
        return true;
    }
    else if (numbers[size_/2] > search_)
    {
        for (int i = size_/2 + 1; i < size_-1; i++)
        {
            numbers[i] = '\0';
        }
        bsearch(numbers, size_/2, search_);
    }
    else
    {
        for (int i = 0; i < size_/2; i++)
        {
            numbers[i] = '\0';
        }
        bsearch(numbers, size_/2 , search_);
    }
    return false;
}