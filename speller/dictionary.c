// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
#define DICTIONARY "dictionaries/large"

FILE *dict;
// Represents a node in a hash table

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    struct node* my_node = malloc(sizeof(struct node));
    char buffer[LENGTH+1];

    dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }
    else
    {
        while (fscanf(dict, "%s", buffer) != EOF)
        {
            int v = hash(buffer);

            strcpy(my_node->word, buffer);

            my_node->next = table[v];
            table[v] = my_node;
        }
        fclose(dict);
        return true;
    }
}


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int v = hash(word);
    struct node* my_node = table[v];

    while(my_node != NULL)
    {
        if (strcasecmp(my_node->word, word) == 0)
        {
            return true;
        }
        my_node = my_node->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        kick(table[i]);
    }
    return true;
}

void kick(struct node* spot)
{
    if (spot != NULL)
    {
        return;
    }

    kick(spot);

    free(spot);
}




//BELOW THIS ARE GOOD FUNCTIONS


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    dict = fopen(DICTIONARY, "r");

    if (dict == NULL)
    {
        return 0;
    }

    char character;
    int counter = 0;

    while((character = fgetc(dict)) != EOF)
    {
        if (character == '\n')
        {
            counter++;
        }
    }
    return counter;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0])-'A';
}

