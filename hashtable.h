// put the interface of hash table here
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#define HASH_SIZE 63 // 26 letters in upper case + 26 letters in lower case + 10 number letters + Other lettes.
struct Word {
	unsigned char *word;  // word name
	unsigned long offset; // offset of the meaning of the word in the dictionary file
	struct Word *next;    // pointer to next word object
};
struct Word* hashdict[HASH_SIZE];

