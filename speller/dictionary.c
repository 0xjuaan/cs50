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
const unsigned int N = 100;

// Hash table
node *table[N];



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int v;

    dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }
    else
    {
        char *buffer = malloc(LENGTH * 1);

        while (fgets(buffer, LENGTH, dict))
        {
            buffer[strcspn(buffer, "\n")] = 0;
            v = hash(buffer);

            table[v] = malloc(sizeof(struct node));

            if (table[v]->has_word == false)
            {
                strcpy(table[v]->word, buffer);
            }
            else
            {
                add(table[v], buffer);
            }
        }
        //After done loading the entire dictionary into the data structure
        return true;
    }
}

void add(struct node* my_node, const char* word_dict)
{
    my_node->next = malloc(sizeof(struct node));

    if (my_node->next->has_word == false)
    {
        strcpy(my_node->next->word,word_dict);
        return;
    }
    else
    {
        add(my_node->next, word_dict);
    }
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    dict = fopen(DICTIONARY, "r");

    char character;
    int counter = 0;

    while((character = fgetc(dict)) != EOF)
    {
        if (character == '\n')
        {
            counter++;
        }
    }
    //printf("Total words: %i\n", counter);
    return counter;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        sum += toupper(word[i]) - 'A';
    }
    double sigmoid = 1/((double) 1 + exp(-0.05 * sum));

    int v = round(100*sigmoid);
    //printf("%i\n", v);
    return v;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int v = hash(word);

    if (strcasecmp(table[v]->word, word) == 0) //Checking if the 1st word is equal to the input word
    {
        return true;
    }
    else if (table[v]->next != NULL && table[v]->next->has_word) //SEGMENTATION FAULT LOCATION
    {
        return lcheck(table[v], word); //If not the 1st word, go forth in the list and return that result
    }
    return true;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        free(table[i]);
    }
    return true;
}

bool lcheck (struct node* my_node, const char* word_dict)
{
    if (strcasecmp(my_node->word, word_dict) == 0) //Checking if the word is equal to the input word
    {
        return true;
    }
    else if (!my_node->next->has_word)
    {
        return false;
    }
    else
    {
        return lcheck (my_node->next, word_dict);
    }

}

