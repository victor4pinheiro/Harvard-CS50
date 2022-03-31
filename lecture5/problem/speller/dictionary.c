// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 300;

// Number of words in dictionary
int number_words = 0;

// Hash table
node *table[300];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *tmp = table[index];

    while (tmp != NULL) {
        if (strcasecmp(word, tmp->word) == 0)
            return true;
        tmp = tmp->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 32;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    if (dictionary == NULL)
        return false;

    FILE *filename = fopen(dictionary, "r");
    char stream[LENGTH + 1] = "\0";

    while (fscanf(filename, "%s", stream) != EOF) {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
            return false;

        strcpy(tmp->word, stream);
        int index = hash(stream);
        tmp->next = table[index];
        table[index] = tmp;
        number_words++;
    }

    fclose(filename);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return number_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        node *tmp = table[i];

        while (tmp) {
            node *cursor = tmp->next;
            free(tmp);
            tmp = cursor;
        }
    }

    return true;
}

// SOURCE FOR LOAD FUNCTION AND SIZE FUNCTION: https://joseph28robinson.medium.com/cs50-pset-5-speller-f9c89d08237e
