#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string words);

int main(void)
{
    // Get input words from both players
    string words[2];
    words[0] = get_string("Player 1: ");
    words[1] = get_string("Player 2: ");

    // Score both words
    int score0 = compute_score(words[0]);
    int score1 = compute_score(words[1]);

    // TODO: Print the winner
}

int compute_score(string words[k])
{
    // TODO: Compute and return score for string
    int n=0;
    int k;
    
    for (int i = 0; i<strlen(words[k]); i++)
    {
        if (isalpha(words[k]))
        {
            int n = tolower(words[k][i]);
            n += POINTS[n-97];
        }
        else
        {
            n+=0;
        }

    }


}
