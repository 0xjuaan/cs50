#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int index;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plain = get_string ("Plaintext: ");
    string cipher = "";

    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            for (int j = 0; j < strlen(alphabet); j++)
            {
                if (plain[i]==alphabet[j])
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
            }
            else
            {
                cipher[i] = tolower(argv[1][index]);
            }
        }
        else
        {
            cipher[i] = plain[i];
        }

    }
    printf("Ciphertext: %s", cipher);
}