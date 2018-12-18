// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "dictionary.h"

// universal root
node *root;

// total number of words added to dictionary
// unsigned int size(void)
unsigned int wordsTotal = 0;

// unload() function helper
void freeNode(node *trav);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // creates reference pointer for current node
    node *trav = root;

    int length = strlen(word);

    // for each letter in input word
    for (int i = 0; i < length; i ++)
    {
        // make each letter of word lowercase to compare to dict words
        char c = tolower(word[i]);

        // to access index of children -> gives back number
        int index = c - 'a';

        if (c == '\'')
        {
            c = 39;  // 123 - 97 = 26
            // apostrophes ascii is supposed to go in 26th position of children[27]
        }

        // try to get the address of children node
        struct node* trav_address = trav->children[index];

        // if the address for the letter exists, check if it's null
        // if NULL, word is misspelled
        if (trav_address == NULL)
        {
            return false;
        }
        else
        {
            trav = trav_address;
        }
    }

        // if true return true
        if (trav->is_word)
        {
            return true;
        }

    // if false then it's an invalid word
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open file pointer that holds dictionary
    FILE *dict = fopen(dictionary, "r");

    // if dictionary file can't be open/read
    if (dict == NULL)
    {
        // unload();
        return false;
    }

    // set wordsTotal to 0 to begin tracking size of trie
    wordsTotal = 0;
    printf("checking wordsTotal: %i\n", wordsTotal);

    // allocate space for root
    root = malloc(sizeof(node));

    // pointer reference to move down trie from root
    node *trav = root;

    // while reading words from file (and not at the end of the file)
    // using int c allows us to use character at a position
    for (char c = tolower(fgetc(dict)); c != EOF; c = tolower(fgetc(dict)))
    {
        // printf("%c\n", c);
        // printf("checking character: %i\n", c);

        // if trav is pointing to null children
        int index = c - 'a';

        // apostrophes ascii is supposed to go in 26th position of children[27]
        if (c == '\'')
        {
            c = 123;
        }

        // if char being read in is the \n for newline
        else if (c == '\n')
        {
            trav->is_word = true;

            // add new word to total words in dictionary
            wordsTotal++;

            printf("%c\n", c);

            // move pointer back to beginning of trie
            trav = root;

        }

        else if (trav->children[index] == NULL)
        {
            // create/malloc for next letter
            trav->children[index] = malloc(sizeof(node));
            // printf("%c", c);
            trav = trav->children[index];
        }



        // if still reading in chars for new word
        // else if next node is already created and child isn't null, point leaf to it
        else
        {
            trav = trav->children[index];
        }

    printf("Total number of words added: %i\n", wordsTotal);
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordsTotal;
}

void freeNode(node *trav)
{
    // free all pointers in children
    for (int i = 0; i < 27; i++)
    if (trav->children[i] != NULL)
    {
        freeNode(trav->children[i]);
    }
    free(trav);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // free root node
    freeNode(root);

    return true;
}

