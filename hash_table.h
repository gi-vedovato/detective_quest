#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure for a clue-suspect relationship
typedef struct ClueSuspect {
    int clueId;
    char suspectName[50];
    struct ClueSuspect *next; // For handling collisions (chaining)
} ClueSuspect;

// Hash table structure
typedef struct HashTable {
    ClueSuspect *table[TABLE_SIZE];
} HashTable;

// Function prototypes for hash table operations
HashTable* createHashTable();
int hashFunction(int clueId);
void insertClueSuspect(HashTable *ht, int clueId, const char *suspectName);
char* searchSuspect(HashTable *ht, int clueId);
void removeClueSuspect(HashTable *ht, int clueId);
void displayHashTable(HashTable *ht);
void freeHashTable(HashTable *ht);

#endif // HASH_TABLE_H
