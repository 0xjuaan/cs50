#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++) //Loop over each voter
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++) //Loop over each preference (note: nested)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int a = 0; a < candidate_count; a++)
    {
        if (strcmp(name, candidates[a]) == 0)
        {
            ranks[rank] = a;
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int b = 0; b < candidate_count-1; b++)   //Iterate over the candidates
    {
        for (int c = b+1; c < candidate_count; c++) //Iterate over the candidates above this one
        {
            preferences[ranks[b]][ranks[c]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int b = 0; b < candidate_count; b++)
    {
        for (int c = 0; c < candidate_count; c++)
        {

            if (preferences[c][b] > 0)
            {
                pairs[pair_count].winner = c;
                pairs[pair_count].loser = b;
                pair_count += 1;
            }
            else
            {
                continue;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
   /* for (int d = 0; d < pair_count-1; d++)
    {
        if (pairs[d].diff < pairs[d+1].diff)
        {
            int temp = pairs[d+1].diff;
            pairs[d+1].diff = pairs[d].diff;
            pairs[d].diff = temp;
        }
        else
        {
            continue;
        }
    }
    return;
    */
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int e = 0; e < pair_count; e++)
    {
        locked [pairs[e].winner][pairs[e].loser] = true;
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int z;
    int topp;
    for (int f = 0; f < candidate_count; f++)
    {
        for (int g = 0; g < pair_count; g++)
        {
            if (f == pairs[g].loser)
            {
                break; //Goes on to the next candidate
            }
            else if (f != pairs[g].loser && g == pair_count - 1 && locked [pairs[g].winner][pairs[g].loser] == true)
            {
                printf("%s\n", candidates[f]);
                return;
            }
            else
            {
                continue; //Check next pair for L
            }
        }

    }
    return;
}
