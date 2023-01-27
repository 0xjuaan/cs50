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

//Visitation/for locking
bool visited[MAX] = {false};

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

int pair_count = 1;
int candidate_count;
int n; //For the locking algorithm's pair_counter
// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool check(pair duos[], int x, int starter);
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
            if (preferences[b][c] > preferences[c][b])
            {
                pairs[pair_count-1].winner = b;
                pairs[pair_count-1].loser = c;
                //printf("Pair %i: [%i][%i]\n", pair_count-1, b, c);
                pair_count++;
            }
        }
    }
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %i: [%i][%i]\n", i, pairs[i].winner, pairs[i].loser);
    }
    printf("how many pairs:%i", pair_count);

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int e = 0;
    while (e < pair_count)
    {
    for (int d = 0; d < pair_count-1; d++)
    {
        if (preferences[pairs[d].winner][pairs[d].loser] < preferences[pairs[d+1].winner][pairs[d+1].loser])
        {
            pair temp = pairs[d+1];
            pairs[d+1] = pairs[d];
            pairs[d] = temp;
            e++;
        }
        else
        {
            e = 0;
            continue;
        }
    }
    return;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < 2; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
    for (int p = 2; p < pair_count; p++)
    {
        if (check(pairs, p, pairs[2].winner))
        {
            locked[pairs[p].winner][pairs[p].loser] = false;
            continue;
        }
        else
        {
            locked[pairs[p].winner][pairs[p].loser] = true;
            continue;
        }
    }
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
                continue; //Check next pair for loser
            }
        }
    }
    return;
}

bool check(pair duos[], int x, int starter)
{
    if (locked[duos[x].winner][duos[x].loser])
    {
        return false;
    }
    else if (duos[x].loser == starter)
    {
        return true;
    }
    else if (duos[pair_count-1].loser == duos[0].winner)
    {
        return true;
    }
    else
    {
        for (int y = 0; y < pair_count; y++)
        {
            if (duos[x].loser == duos[y].winner)
            {
                return check(pairs, y, duos[x].winner);
            }
            else
            {
                continue;
            }
        }
        return false;
    }
}

//check50 cs50/problems/2023/x/tideman