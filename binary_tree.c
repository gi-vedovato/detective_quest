#include "binary_tree.h"

// Create a new room node
Room* createRoom(const char *name, const char *description) {
    Room *newRoom = (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
        printf("Erro ao alocar memória para o cômodo\n");
        return NULL;
    }
    
    strncpy(newRoom->name, name, sizeof(newRoom->name) - 1);
    newRoom->name[sizeof(newRoom->name) - 1] = '\0';
    
    strncpy(newRoom->description, description, sizeof(newRoom->description) - 1);
    newRoom->description[sizeof(newRoom->description) - 1] = '\0';
    
    newRoom->left = NULL;
    newRoom->right = NULL;
    
    return newRoom;
}

// Insert a room to the left of a parent room
void insertLeft(Room *parent, const char *name, const char *description) {
    if (parent == NULL) {
        printf("Cômodo pai inválido\n");
        return;
    }
    
    if (parent->left != NULL) {
        printf("Já existe um cômodo à esquerda\n");
        return;
    }
    
    parent->left = createRoom(name, description);
}

// Insert a room to the right of a parent room
void insertRight(Room *parent, const char *name, const char *description) {
    if (parent == NULL) {
        printf("Cômodo pai inválido\n");
        return;
    }
    
    if (parent->right != NULL) {
        printf("Já existe um cômodo à direita\n");
        return;
    }
    
    parent->right = createRoom(name, description);
}

// Display the mansion map with indentation
void displayMansionMap(Room *root, int level) {
    if (root == NULL) {
        return;
    }
    
    // Print indentation
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    printf("- %s: %s\n", root->name, root->description);
    
    // Display left and right rooms
    if (root->left != NULL || root->right != NULL) {
        displayMansionMap(root->left, level + 1);
        displayMansionMap(root->right, level + 1);
    }
}

// Search for a room by name
Room* searchRoom(Room *root, const char *name) {
    if (root == NULL) {
        return NULL;
    }
    
    if (strcmp(root->name, name) == 0) {
        return root;
    }
    
    // Search in left subtree
    Room *found = searchRoom(root->left, name);
    if (found != NULL) {
        return found;
    }
    
    // Search in right subtree
    return searchRoom(root->right, name);
}

// Free all memory allocated for the mansion map
void freeMansionMap(Room *root) {
    if (root == NULL) {
        return;
    }
    
    freeMansionMap(root->left);
    freeMansionMap(root->right);
    free(root);
}
