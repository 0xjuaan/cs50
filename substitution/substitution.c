#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plain = get_string ("Plaintext: ");

    for (int i = 0; i < strlen(plain); i++)
    {
        if (alpha(plain[i]))
        {
            for (int j = 0; j < strlen(alphabet); j++)
            {
                if (plain[i]==alphabet[j])
                {
                    int index = j;
                }
            }
        }
    }
}