// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

// define node structure
typedef struct node
{
    bool is_word;
    // node pointers
    struct node* children[27];
}
node;

// creates the root node (initialized to NULL)
struct node *root;


#endif // DICTIONARY_H
