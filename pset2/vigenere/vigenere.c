// Program that encrypts messages using Vigenère’s cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argc is argument count int type variable - how much stuff did the user type?
//argv is an array of strings = user input
int main(int argc, string argv[])
{
    int j;
    int k;  // to hold current character of the alphabet
    int count = 0;  // Each time we pass through the loop - use the next character in the keyword

    // Make sure that user enters only 1 secret key
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\nPlease enter only 1 key:\n");
        return 1;   // signals error - try again
    }

    // Variable for secret keyword from command-line
    string key = argv[1];
    // Check that only alphabetic characters were entered as input
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Keyword may only contain alphabetic characters.\n");
            //  Error and exit
            return 1;
        }
    }

    // User input for word to cipher
    string plainText = get_string("plaintext:");

    //  Print the word ciphertext to user
    printf("ciphertext: ");

    //  Loop through plaintext characters
    for (int i = 0; i < strlen(plainText); i++)
    {
        //  If char is lowercase = print lowercase cipher
        if (islower(plainText[i]))
        {
            j = (count % strlen(key));  // number of loop % length of keyword
            k = (tolower(key[j]) - 97);  // holding current alpha character of key
            count += 1; // increase loop by 1
            printf("%c", (((plainText[i] + k) - 97) % 26) + 97);
        }

        else if (isupper(plainText[i]))
        {
            j = (count % strlen(key)); // number of loop % length of keyword
            k = (tolower(key[j]) - 97);  // holding current alpha character of key
            count += 1; // increase loop by 1
            printf("%c", (((plainText[i] + k) - 65) % 26) + 65);
        }

        // Print all chars OTHER than alphabetic
        else
        {
            //If the char is not alpha (punctuation etc.) -then print its char
            printf("%c", plainText[i]);
        }
    }

    // Print a new line
    printf("\n");

    // Return 0 and exit program
    return 0;
}



