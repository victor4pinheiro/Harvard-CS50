// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[26];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    if (fopen("dictionaries/large", "r") == NULL)
        return false;

    FILE *dictionary_file = fopen("./dictionaries/large", "r");
    struct stat file;
    stat("./dictionaries/large", &file);

    char *stream = malloc(file.st_size);

    while(fscanf(dictionary_file, "%s", stream) != EOF) {
        if (malloc(sizeof(node)) == NULL)
            return false;

        node *tmp = malloc(sizeof(node));
        strcpy(tmp->word, stream);
        tmp->next = NULL;

        int index = hash(tmp->word);

        do {
            if (strcmp(table[index]->word, "\0") == 0) {
                strcpy(table[index]->word, tmp->word);
                table[index]->next = tmp->next;
                break;
            }
        } while (strcmp(table[index]->word, "\0") != false);
    }

    fclose(dictionary_file);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
