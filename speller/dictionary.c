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

            if (table[v] == NULL)
            {
                table[v] = malloc(sizeof(struct node));
                table[v]->has_word = false;
                table[v]->next = NULL;
            }

            if (table[v]->has_word == false)
            {
                strcpy(table[v]->word, buffer); //Fill in dis 1st value
                table[v]->has_word = true; //Now set it to have a value since we just gave it one
            }
            else
            {
                table[v]->next = malloc(sizeof(struct node)); //Allocating RAM to the 2nd one
                table[v]->next->has_word = false;
                table[v]->next->next = NULL;
                add(table[v]->next, buffer);
            }
        }
        //After done loading the entire dictionary into the data structure
        return true;
    }
}

void add(struct node* my_node, const char* word_dict)
{
    if (my_node->has_word == false)
    {
        strcpy(my_node->word,word_dict);
        my_node->has_word = true; // Fill this space with the word from the dictionary
        return;
    }
    else
    {
        my_node->next = malloc(sizeof(struct node)); //Allocate RAM to next node

        my_node->next->has_word = false;

        my_node->next->next = NULL;

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
    return toupper(word[0])-'A';
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int v = hash(word);
    if (table[v] == NULL) //If there is no ting for this hash_value
    {

        return false;
    }
    else if (strcasecmp(table[v]->word, word) == 0) //Checking if the 1st word is equal to the input word
    {
        return true;
    }
    else if (table[v]->next == NULL) //If the next node was not made
    {
        return false;
    }
    else
    {
        return lcheck(table[v]->next, word);
    }

    return false;
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
        return true; //We got the word in the dict
    }
    else if (my_node->next == NULL)
    {

        return false; //Word aint in the dict
    }
    else
    {
        return lcheck (my_node->next, word_dict);
    }
}

