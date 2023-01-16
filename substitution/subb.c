#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    if (argc == 2 && strlen(argv[1])==26)
    {
        //Defining a couple of things (variables and array)
        string plaintext = get_string("Plaintext: ");
        int size = strlen(plaintext);
        char ciphertext[size];
        int index;
        bool upper;

        //Looping the check of the plaintext characters (1 by 1)
        for (int i=0; i<size; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    upper = true;
                }
                else
                {
                    upper = false;
                }
                //Finding the index of the plaintext character
                for (int j=0; j<26; j++)
                {
                    if (tolower(plaintext[i]) == alphabet[j])
                    {
                        index = j;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                ciphertext[i]= plaintext[i];
            }

            //Giving values to ciphertext (based off the index of plaintext)
            if (upper)
            {
                ciphertext[i] = argv[1][index];
            }
            else
            {
                ciphertext[i] = tolower(argv[1][index]);
            }

        }
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        return 1;
    }
}