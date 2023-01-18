#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Usage: ./wordle wordsize\n");
    }
    int wordsize = 0;

    if (atoi(argv[1]) == 5)
    {
        wordsize = 5;
    }
    else if (atoi(argv[1]) == 6)
    {
          wordsize = 6;
    }
    else if (atoi(argv[1]) == 7)
    {
         wordsize = 7;
    }
    else if (atoi(argv[1]) == 8)
    {
          wordsize = 8;
    }
    else
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
    }


    // TODO #2
    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;


    //GREETING (BEGINNING)
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
        else
        {
            continue;
        }
    }

    // Print the game's result
    if (won)
    {
        printf("You Won!");
    }
    else
    {
        printf("You ran out of your %i guesses. The word was %s\n",guesses, choice);
    }
    // that's all folks!
    return 0;
}

string get_guess(int wordsize)
{
    string guess;
    do
    {
    guess = get_string ("Input a %i-letter word: ", wordsize);
    }
    while (strlen(guess) != wordsize);
    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    //Compare guess VS choice     [Fishy]       Mafey
    int score = 0;
    for (int a = 0; a < wordsize; a++)
    {
        for (int b = 0; b < wordsize; b++)
        {
            if (tolower(guess[a]) == choice[b])
            {
                if (a==b)
                {
                    status[a] = EXACT;
                    score += EXACT;
                }
                else
                {
                    status[a] = CLOSE;
                    score += CLOSE;
                }
                break;
            }
            else
            {
                continue;
            }
        }
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    for (int x = 0; x < wordsize; x++)
    {
        switch (status[x])
        {
            case 0:
                printf(RED"%c"RESET"", guess[x]);
                continue;
            case 1:
                printf(YELLOW"%c"RESET"", guess[x]);
                continue;
            case 2:
                printf(GREEN"%c"RESET"", guess[x]);
                continue;
        }
    }
    printf("\n");
    return;
}
