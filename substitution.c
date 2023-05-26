#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Command line argument is the Cipher Key
// Once a correct key is input, the program will ask for plaintext:
// After plaintext is input, ciphertext using the user-provided key will be output.

int main(int argc, string argv[])
{
    // Check to ensure only 1 command line argument has been input (just the key)
    if (argc != 2)
    {
        printf("Usage ./substitution key\n");
        return 1;
    }

    // Key is to be used from here on out for easiest readability of code.
    string key = argv[1];

    // Checks for non-letter characters being used
    for (int i = 0; i < 26; i++)
    {
        char letter_check = key[i];
        if (letter_check < 65 || (letter_check > 90 && letter_check < 97) || letter_check > 122)
        {
            printf("Substitution key must be all letters\n");
            return 1;
        }
    }

    // Checks for duplicates
    for (int i = 0; i < 26; i++)
    {
        char j = tolower(key[i]);
        for (int k = 0; k < 26; k++)
        {
            if (j == tolower(key[k]))
            {
                if (i != k)
                {
                    printf("Duplicate characters are not allowed in the key.\n");
                    return 1;
                }
            }
        }
    }


    // checks to ensure the key is 26 charcters.
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }


    // Obtain plain text from the user to encrypt
    string p = get_string("plaintext: ");


    // Create a string to hold the Ciphertext
    int n = strlen(p);
    char c[n];

    // Made this loop to make every position in the cipherstring to be 0
    // because for some reason the positions in the array started recieveing
    // non-zero inputs.

    for (int i = 0; i <= n; i++)
    {
        c[i] = 0;
    }

    //loop to convert key to lowercase for loop creating cipher
    for (int i = 0; i <= 26; i++)
    {
        key[i] = tolower(key[i]);
    }

    // loop to convert the plain text to ciphertext while maintiaing
    // capitalization and punctutation provided in plain text
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (islower(p[i]))
        {
            c[i] = key[(p[i] - 97)];
        }
        else if (isupper(p[i]))
        {
            c[i] = key[tolower(p[i]) - 97];
            c[i] = toupper(c[i]);
        }
        else if (p[i] >= 32 && p[i] <= 64)
        {
            c[i] = p[i];
        }
        else if (p[i] == 0)
        {
            c[i] = p[i];
        }
    }
    printf("ciphertext: %s\n", c);
    return 0;
}