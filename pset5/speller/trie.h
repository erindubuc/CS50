// functions to help with trie structure for dictionary.c

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// define node structure
typedef struct node
{
    bool is_word;
    // node pointers
    struct node* children[27];
}
node;

// beginning of trie -> root and traveler
node *root;
node *trav;

// prototypes
int getChildIndex (char c);
node *getNode();

// function that returns a new trie node
node *getNode (node *newNode)
{
    newNode = malloc(sizeof(node));

    if (newNode == NULL)
        return NULL;

    for (int i = 0; i < 27; i++)
    {
        newNode->children[i] = NULL;
    }

    newNode->is_word = false;
    return newNode;
}

// function that frees all traveling pointers up to root
void freeNode(node *travel)
{
    // free all pointers in children
    for (int i = 0; i < 27; i++)
    if (travel->children[i] != NULL)
    {
        freeNode(travel->children[i]);
    }
    free(travel);
}

// help from: https://www.techiedelight.com/trie-implementation-insert-search-delete/
// https://medium.com/basecs/trying-to-understand-tries-3ec6bede0014