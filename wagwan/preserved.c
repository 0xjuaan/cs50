/*/ Implements a dictionary's functionality
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
                //Allocate memory to store a node* in table[v]

                table[v] = malloc(sizeof(struct node));
                table[v]->has_word = false;
                table[v]->next = NULL;
            }

            if (table[v]->has_word == false) //i.e , we just made this one
            {
                strcpy(table[v]->word, buffer); //Fill in dis 1st value
                table[v]->has_word = true; //Now set it to have a value since we just gave it one

                //Allocate and initialise the 2nd one
                table[v]->next = malloc(sizeof(struct node));
                table[v]->next->has_word = false;
                table[v]->next->next = NULL;
            }
            else //If this one is filled up
            {
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
    if (strcasecmp(my_node->word, word_dict) == 0)
    {
        return true;
    }
    else if (my_node->next == NULL)
    {
        return false;
    }
    else
    {
        return lcheck(my_node->next, word_dict);
    }
}










//lcheck function saved


   if (strcasecmp(my_node->word, word_dict) == 0) //Checking if the word is equal to the input word
    {
        return true; //We got the word in the dict
    }
    else if (my_node->next == NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("\n");
        }
        return false; //Word aint in the dict
    }
    else
    {
        return lcheck (my_node->next, word_dict);
    }
    */

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

            node* my_node = table[v]; //table[v] is a pointer to a node (also the cursor rn)

            label:

            if (my_node == NULL)
            {
                //Allocate memory to store a node* in this node
                my_node = malloc(sizeof(struct node));
                my_node->has_word = false;
                //my_node->next = NULL;

                // Set the corresponding element in the table to point to the new node
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
        struct node *my_node;

        while (fgets(buffer, LENGTH, dict)) //Get a string from the dictionary (1 word)
        {
            buffer[strcspn(buffer, "\n")] = 0; //Remove the \n from it

            v = hash(buffer); //Hash the word

            if (table[v] == NULL)
            {
                table[v] = malloc(sizeof(node));

                strcpy(table[v]->word, buffer);
                table[v]->has_word = true;

                my_node = table[v];
                break;
            }

            label:

            if (my_node == NULL)
            {
                //Allocate memory to store a node* in this node
                my_node = malloc(sizeof(struct node));
                my_node->has_word = false;
                //my_node->next = NULL;
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