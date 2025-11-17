#include "hash_table.h"

// Create a new hash table
HashTable* createHashTable() {
    HashTable *ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        printf("Erro ao alocar memória para a tabela hash\n");
        return NULL;
    }
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    
    return ht;
}

// Hash function to determine index
int hashFunction(int clueId) {
    return clueId % TABLE_SIZE;
}

// Insert a clue-suspect relationship
void insertClueSuspect(HashTable *ht, int clueId, const char *suspectName) {
    if (ht == NULL) {
        printf("Tabela hash inválida\n");
        return;
    }
    
    int index = hashFunction(clueId);
    
    // Create new clue-suspect node
    ClueSuspect *newNode = (ClueSuspect*)malloc(sizeof(ClueSuspect));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o vínculo pista-suspeito\n");
        return;
    }
    
    newNode->clueId = clueId;
    strncpy(newNode->suspectName, suspectName, sizeof(newNode->suspectName) - 1);
    newNode->suspectName[sizeof(newNode->suspectName) - 1] = '\0';
    
    // Handle collision using chaining
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search for a suspect by clue ID
char* searchSuspect(HashTable *ht, int clueId) {
    if (ht == NULL) {
        return NULL;
    }
    
    int index = hashFunction(clueId);
    ClueSuspect *current = ht->table[index];
    
    while (current != NULL) {
        if (current->clueId == clueId) {
            return current->suspectName;
        }
        current = current->next;
    }
    
    return NULL;
}

// Remove a clue-suspect relationship
void removeClueSuspect(HashTable *ht, int clueId) {
    if (ht == NULL) {
        printf("Tabela hash inválida\n");
        return;
    }
    
    int index = hashFunction(clueId);
    ClueSuspect *current = ht->table[index];
    ClueSuspect *prev = NULL;
    
    while (current != NULL) {
        if (current->clueId == clueId) {
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Vínculo da pista #%d removido\n", clueId);
            return;
        }
        prev = current;
        current = current->next;
    }
    
    printf("Vínculo da pista #%d não encontrado\n", clueId);
}

// Display all clue-suspect relationships
void displayHashTable(HashTable *ht) {
    if (ht == NULL) {
        printf("Tabela hash inválida\n");
        return;
    }
    
    printf("\n=== Vínculos Pista-Suspeito ===\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("Índice %d: ", i);
            ClueSuspect *current = ht->table[i];
            while (current != NULL) {
                printf("[Pista #%d -> %s] ", current->clueId, current->suspectName);
                current = current->next;
            }
            printf("\n");
        }
    }
}

// Free all memory allocated for the hash table
void freeHashTable(HashTable *ht) {
    if (ht == NULL) {
        return;
    }
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        ClueSuspect *current = ht->table[i];
        while (current != NULL) {
            ClueSuspect *temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(ht);
}
