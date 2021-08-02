// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
	char word[LENGTH + 1];
	struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 200;

// Hash table
node *table[N];

unsigned int dictsize = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
	//makes a lowercase copy
	char WORD[strlen(word)];
	strcpy(WORD, word);
	for (int i = 0; i < strlen(word); i++)
	{
		WORD[i] = tolower(word[i]);
	}

	int hashed = hash(word);
	node *n = table[hashed];
	while (n != NULL)
	{
		if (strcmp(WORD, n->word) == 0)
		{
			return true;
		}

		n = n->next;
	}
	return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
	long sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum += tolower(word[i]);
	}
	return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
	FILE *dict = fopen(dictionary, "r");
	if (dict == NULL)
	{
		printf("file unable to load\n");
		return false;
	}
	char word_next[LENGTH + 1];

	//reading file;
	while (fscanf(dict, "%s", word_next) != EOF)
	{
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			printf("Not enough memory");
			return false;
		}
		strcpy(n->word, word_next);
		int hashed = hash(word_next);
		n->next = table[hashed];
		table[hashed] = n;
		dictsize++;
	}
	fclose(dict);

	return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
	return dictsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
	for (int i = 0; i < N; i++)
	{
		node *n = table[i];

		while (n != NULL)
		{
			node *tmp = n;
			n = n->next;
			free(tmp);
		}

		if (n == NULL && i == N - 1)
		{
			return true;
		}
	}
	return false;
}
