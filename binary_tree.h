#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a room in the mansion
typedef struct Room {
    char name[50];
    char description[200];
    struct Room *left;  // Left room connection
    struct Room *right; // Right room connection
} Room;

// Function prototypes for binary tree operations
Room* createRoom(const char *name, const char *description);
void insertLeft(Room *parent, const char *name, const char *description);
void insertRight(Room *parent, const char *name, const char *description);
void displayMansionMap(Room *root, int level);
Room* searchRoom(Room *root, const char *name);
void freeMansionMap(Room *root);

#endif // BINARY_TREE_H
