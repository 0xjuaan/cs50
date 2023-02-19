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
            node* my_node = table[v];

            if (my_node == NULL)
            {
                //Allocate memory to store a node* in this node
                my_node = malloc(sizeof(struct node));
                my_node->has_word = false;
                my_node->next = NULL;
            }

            if (my_node->has_word == false) //i.e , we just made this one
            {
                strcpy(my_node->word, buffer); //Fill in dis 1st value
                my_node->has_word = true; //Now set it to have a value since we just gave it one

                //Allocate and initialise the 2nd one
                my_node->next = malloc(sizeof(struct node));
                my_node->next->has_word = false;
                my_node->next->next = NULL;
            }
            else //If this one is filled up
            {

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

        //Allocate and initialise the next one
        my_node->next = malloc(sizeof(struct node));
        my_node->next->has_word = false;
        my_node->next->next = NULL;
        return;
    }
    else //If this one is filled up
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
    return toupper(word[0])-'A';
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int v = hash(word);
    node *my_node = table[v];

    while (my_node != NULL)
    {
        if (strcasecmp(my_node->word, word) == 0)
        {
            my_node = my_node->next;
            return true;
        }
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





