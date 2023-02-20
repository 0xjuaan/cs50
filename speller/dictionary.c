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
        char *buffer = malloc(LENGTH);

        while (fgets(buffer, LENGTH, dict)) //Get a string from the dictionary (1 word)
        {
            buffer[strcspn(buffer, "\n")] = 0; //Remove the \n from it

            v = hash(buffer); //Hash the word

            node* my_node = table[v];

            label:

            if (my_node == NULL)
            {
                //Allocate memory to store a node* in this node
                my_node = malloc(sizeof(struct node));
                my_node->has_word = false;
                //my_node->next = NULL;

                table[v] = my_node;
            }

            if (my_node->has_word == false) //Reached an empty node
            {
                strcpy(my_node->word, buffer); //Fill in dis value
                my_node->has_word = true;

                //Allocate and initialise the 2nd one
                my_node->next = malloc(sizeof(struct node));
                my_node->next->has_word = false;
                //my_node->next->next = NULL;
            }

            else //If this one is filled up
            {
                my_node = my_node->next;
                goto label;
            }
        }
        //After done loading the entire dictionary into the data structure
        return true;
    }
}


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int v = hash(word);
    struct node* my_node = table[v];

    label1:

    if (my_node == NULL)
    {
        printf("***%s***", my_node->word);
        return false; //We reached the end but cant find a match
    }

    else if (strcasecmp(my_node->word, word) == 0)
    {
        return true; //This is da word
    }
    else
    {
        my_node = my_node->next;
        goto label1;
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

