#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool argcheck(string argv[], int argc);
int j;
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
  //INVALID KEY
    if (argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1])!=26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else if (argcheck(argv, argc) == false)
    {
        printf("Key must contain only one of each alphabet\n");
        return 1;
    }

     //WHAT HAPPENS WHEN KEY IS VALID
    else
    {

        string plain = get_string ("Plaintext: ");
        int size = strlen(plain);
        char cipher[size];
        cipher[size] = '\0';
        alphabet = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < size; i++)
        {
            if (isalpha(plain[i]))
            {
                for (j = 0; j < strlen(alphabet); j++)
                {
                    if (tolower(plain[i]) == alphabet[j])
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (isupper(plain[i]))
                {
                    cipher[i] = toupper(argv[1][j]);
                    continue;
                }
                else
                {
                    cipher[i] = tolower(argv[1][j]);
                    continue;
                }
            }
        else
        {
            cipher[i] = plain[i];
            continue;
        }

    }
        printf("ciphertext: %s\n", cipher);
        return 0;
    }
}

//Defining the key-checker function

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
            if (tolower(argv[1][a]) == alphabet[b])
            {

                c++;
                alphabet[b] = '#';
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
