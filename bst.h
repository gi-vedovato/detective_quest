#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a clue in the BST
typedef struct Clue {
    int id;
    char category[50];
    char description[200];
    struct Clue *left;
    struct Clue *right;
} Clue;

// Function prototypes for BST operations
Clue* createClue(int id, const char *category, const char *description);
Clue* insertClue(Clue *root, int id, const char *category, const char *description);
Clue* searchClue(Clue *root, int id);
Clue* findMin(Clue *node);
Clue* removeClue(Clue *root, int id);
void displayClues(Clue *root);
void displayCluesByCategory(Clue *root, const char *category);
void freeClues(Clue *root);

#endif // BST_H
