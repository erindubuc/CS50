// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#include "trie.h"

// universal root
node *root;
node *trav;

// total number of words added to dictionary
// unsigned int size(void)
unsigned int wordsTotal = 0;

// function to return a new trie node initialized to null
node *getNode(node *newNode);

// unload() function helper
void freeNode(node *travel);

// to get index of letter within children[index]
    // if c is an apostrophe, if c is lowercase, else if c is uppercase
int getChildIndex (char c)
{
    if (c == '\'')
        return 26;
    else if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A';
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // creates reference pointer for current node
    trav = root;

    int length = strlen(word);

    int index = 0;

    // for each letter in input word
    for (int i = 0; i < length; i ++)
    {
        // get index for each letter of word being checked
        index = getChildIndex(word[i]);

        if (trav->children[index] == NULL)
            return false;

        else
            trav = trav->children[index];
    }

        // if true return true
        if (trav->is_word == true)
            return true;

        else
            // if false then it's an invalid word
            return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // create way to traverse from root
    root = getNode(trav);
    trav = root;
    // create pointer from trav to traverse down rest of word
    node *new_trav;

    // set wordsTotal to 0 to begin tracking size of trie
    wordsTotal = 0;

    // initialize index
    int index = 0;

    // open file pointer that holds dictionary
    FILE *dict = fopen(dictionary, "r");

    // if dictionary file can't be open/read
    if (dict == NULL)
    {
        // unload();
        return false;
    }

    // while reading words from file (and not at the end of the file)
    // using int c allows us to use character at a position
    for (char c = fgetc(dict); c != EOF; c = fgetc(dict))
    {

        // pointer reference to move down trie from root
        new_trav = trav;

        // if c is not the end of a line - reading within word
        if (c != '\n')
        {
            index = getChildIndex(c);
            if (index >= 0 && index <= 26)
            {
                // if letter is not in the node - malloc new node for it
                if (trav->children[index] == NULL)
                {
                    trav->children[index] = getNode(trav->children[index]);
                }

                // if letter is there within the node, move on to it
                new_trav = trav->children[index];
                trav = trav->children[index];
            }
        }

        // if character being read in is the \n for newline
        else
        // if (c == '\n')
        {
            trav->is_word = true;

            // move pointer back to beginning of trie
            trav = root;

            // add new word to total words in dictionary
            wordsTotal++;
        }

    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordsTotal;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // free root node
    freeNode(root);

    return true;
}

