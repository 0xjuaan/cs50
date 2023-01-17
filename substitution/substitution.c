#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plain = get_string ("Plaintext: ");
    int size = strlen(plain);
    char cipher[size];

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
                cipher[i] = argv[1][index];
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
}