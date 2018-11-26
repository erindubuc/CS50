// Program that encrypts messages using Caesar’s cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argc is argument count int type variable - how much stuff did the user type?
//argv is an array of strings = user input
int main(int argc, string argv[])
{

    int index;  //variable to access ascii character positions

    // Make sure that user enters only 1 secret key
    if (argc != 2)   //# of command line args sent from user (./caesar key)
    {
        printf("Usage: ./caesar k\nPlease enter only 1 key:\n");
        return 1;   //signals error
    }

    // User input
    string plainText = get_string("plaintext:");

    // User command-line input converted it to an integer
    int key = atoi(argv[1]); // stores secret key as an integer

    //  Print the word ciphertext to user
    printf("ciphertext: ");

    // While the ith char is less than strlen of plaintext, loop through characters
    for (int i = 0; i < strlen(plainText); i++)
    {
        //Check to see if char is alpha or not
        if (isalpha(plainText[i]))
        {
            //  If char is alpha AND lowercase = print lowercase cipher
            if (islower(plainText[i]))
            {
                // plaintext[i] + 97 + key => (sum) % __ +97 == new index position
                index = (plainText[i] - 97 + key) % 26 + 97; //shift plaintext character by key
            }

            else if (isupper(plainText[i]))
            {
                // plaintext[i] + 65 + key => (sum) % __ +65 == new index position
                index = (plainText[i] - 65 + key) % 26 + 65; //shift plaintext character by key
            }

            //Store variable to reference the cipher chars from key/ascii table
            char cipher = index;

            //Print char that matches ascii value
            printf("%c", cipher);
        }

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
