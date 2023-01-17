#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool wemadeit;
bool argcheck(string key, int argc, string alphabet);


int main(int argc, string argv[])
{

    string key = argv[1];
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plain = get_string ("Plaintext: ");
    int size = strlen(plain);
    char cipher[size];

    argcheck(key, argc, alphabet);
    //WHAT HAPPENS WHEN KEY IS VALID
    if (argcheck(key, argc, alphabet) == true)
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
    else if (wemadeit == 1)
    {
        printf("Key must contain only one of each alphabet\n");
    }




}



 bool argcheck(string key, int argc, string alphabet)
{
    int c = 0;

    if (argc==2)
    {
        if (strlen(key)==26)
        {
            wemadeit = true;
            for (int a = 0; a < 26; a++)
            {
                for (int b = 0; b < 26; b++)
                {
                    if (key[a] == alphabet[b])
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


        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    if (c == 26)
    {
        return true;
    }
    

}
