#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

    if (argc == 2)
    {
        string plaintext = get_string("Plaintext: ");
        char ciphertext[strlen(plaintext)];
        int index;
        
        for (int i=0; i<strlen(plaintext); i++)
        {
            for (int j=0; j<26; j++)
            {
                if (plaintext[i] == alphabet[j])
                {
                    index = j;
                }
                else
                {
                    continue;
                }
            }
            ciphertext[i]=argv[1][index];

        }
        printf("ciphertext: %s", ciphertext);
        return 0;
    }
    else
    {
        return 1;
    }
}