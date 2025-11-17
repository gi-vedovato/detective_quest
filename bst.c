#include "bst.h"

// Create a new clue node
Clue* createClue(int id, const char *category, const char *description) {
    Clue *newClue = (Clue*)malloc(sizeof(Clue));
    if (newClue == NULL) {
        printf("Erro ao alocar memória para a pista\n");
        return NULL;
    }
    
    newClue->id = id;
    
    strncpy(newClue->category, category, sizeof(newClue->category) - 1);
    newClue->category[sizeof(newClue->category) - 1] = '\0';
    
    strncpy(newClue->description, description, sizeof(newClue->description) - 1);
    newClue->description[sizeof(newClue->description) - 1] = '\0';
    
    newClue->left = NULL;
    newClue->right = NULL;
    
    return newClue;
}

// Insert a clue into the BST
Clue* insertClue(Clue *root, int id, const char *category, const char *description) {
    if (root == NULL) {
        return createClue(id, category, description);
    }
    
    if (id < root->id) {
        root->left = insertClue(root->left, id, category, description);
    } else if (id > root->id) {
        root->right = insertClue(root->right, id, category, description);
    } else {
        printf("Pista com ID %d já existe\n", id);
    }
    
    return root;
}

// Search for a clue by ID
Clue* searchClue(Clue *root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    
    if (id < root->id) {
        return searchClue(root->left, id);
    }
    
    return searchClue(root->right, id);
}

// Find the minimum value node
Clue* findMin(Clue *node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Remove a clue from the BST
Clue* removeClue(Clue *root, int id) {
    if (root == NULL) {
        printf("Pista com ID %d não encontrada\n", id);
        return NULL;
    }
    
    if (id < root->id) {
        root->left = removeClue(root->left, id);
    } else if (id > root->id) {
        root->right = removeClue(root->right, id);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Clue *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Clue *temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children
        Clue *temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->category, temp->category);
        strcpy(root->description, temp->description);
        root->right = removeClue(root->right, temp->id);
    }
    
    return root;
}

// Display all clues in order (in-order traversal)
void displayClues(Clue *root) {
    if (root == NULL) {
        return;
    }
    
    displayClues(root->left);
    printf("Pista #%d [%s]: %s\n", root->id, root->category, root->description);
    displayClues(root->right);
}

// Display clues by category
void displayCluesByCategory(Clue *root, const char *category) {
    if (root == NULL) {
        return;
    }
    
    displayCluesByCategory(root->left, category);
    
    if (strcmp(root->category, category) == 0) {
        printf("Pista #%d [%s]: %s\n", root->id, root->category, root->description);
    }
    
    displayCluesByCategory(root->right, category);
}

// Free all memory allocated for clues
void freeClues(Clue *root) {
    if (root == NULL) {
        return;
    }
    
    freeClues(root->left);
    freeClues(root->right);
    free(root);
}
