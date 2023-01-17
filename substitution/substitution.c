#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool wemadeit;
bool argcheck(string argv[], int argc);
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(int argc, string argv[])
{
    string plain = get_string ("Plaintext: ");
    int size = strlen(plain);
    char cipher[size];

    argcheck(argv, argc);
    //WHAT HAPPENS WHEN KEY IS VALID
    if (argcheck(argv, argc) == true)
    {
        for (int i = 0; i < size; i++)
        {
        int index;
        if (isalpha(plain[i]))
        {
            for (int j = 0; j < strlen(alphabet); j++)
            {
                if (toupper(plain[i]) == alphabet[j])
                {
                    index = j;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (isupper(plain[i]))
            {
                cipher[i] = toupper(argv[1][index]);
                continue;
            }
            else
            {
                cipher[i] = tolower(argv[1][index]);
                continue;
            }
        }
        else
        {
            cipher[i] = plain[i];
            continue;
        }

    }
        printf("Ciphertext: %s\n", cipher);
        return 0;
    }

    //OTHER POSSIBILITIES (INVALID KEY)

    else if (argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1])!=26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else if ( == 1)
    {
        printf("Key must contain only one of each alphabet\n");
    }




}

bool argcheck(string argv[], int argc)
{
    int c = 0;
    if (argc!=2)
    {
        return false;
    }
    else if (strlen(argv[1])!=26)
    {
        return false;
    }
    for (int a = 0; a < 26; a++)
    {
        for (int b = 0; b < 26; b++)
        {
            if (argv[1][a] == alphabet[b])
            {
                c++;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    if (c==26)
    {
        return true;
    }
    else
    {
        return false;
    }
}
