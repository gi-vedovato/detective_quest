#include <stdio.h>
#include "binary_tree.h"
#include "bst.h"
#include "hash_table.h"

void printSeparator() {
    printf("\n================================================\n");
}

void demonstrateMansionMap() {
    printSeparator();
    printf("=== MAPA DA MANSÃO (Árvore Binária) ===\n");
    printSeparator();
    
    // Create mansion map using binary tree
    Room *entrance = createRoom("Entrada", "O hall principal da mansão");
    insertLeft(entrance, "Biblioteca", "Repleta de livros antigos e poeira");
    insertRight(entrance, "Sala de Jantar", "Mesa grande com velas acesas");
    
    Room *library = entrance->left;
    insertLeft(library, "Escritório", "Mesa com documentos espalhados");
    insertRight(library, "Sala Secreta", "Escondida atrás da estante");
    
    Room *diningRoom = entrance->right;
    insertLeft(diningRoom, "Cozinha", "Cheira a comida estragada");
    insertRight(diningRoom, "Adega", "Garrafas de vinho cobertas de teia");
    
    printf("\nMapa completo da mansão:\n");
    displayMansionMap(entrance, 0);
    
    // Search for a specific room
    printf("\n--- Busca de Cômodo ---\n");
    char searchName[] = "Sala Secreta";
    Room *found = searchRoom(entrance, searchName);
    if (found != NULL) {
        printf("Cômodo encontrado: %s - %s\n", found->name, found->description);
    } else {
        printf("Cômodo '%s' não encontrado\n", searchName);
    }
    
    freeMansionMap(entrance);
}

void demonstrateClueOrganization() {
    printSeparator();
    printf("=== ORGANIZAÇÃO DE PISTAS (Árvore de Busca) ===\n");
    printSeparator();
    
    Clue *clueTree = NULL;
    
    // Insert clues with different IDs and categories
    clueTree = insertClue(clueTree, 5, "Física", "Impressão digital na porta");
    clueTree = insertClue(clueTree, 3, "Testemunhal", "Vizinho viu sombra às 22h");
    clueTree = insertClue(clueTree, 7, "Física", "Cabelo loiro no sofá");
    clueTree = insertClue(clueTree, 2, "Documental", "Carta ameaçadora encontrada");
    clueTree = insertClue(clueTree, 8, "Testemunhal", "Mordomo ouviu discussão");
    clueTree = insertClue(clueTree, 4, "Física", "Marca de sapato no jardim");
    clueTree = insertClue(clueTree, 6, "Documental", "Recibo de passagem de trem");
    
    printf("\nTodas as pistas (ordenadas por ID):\n");
    displayClues(clueTree);
    
    // Search for a specific clue
    printf("\n--- Busca de Pista ---\n");
    int searchId = 5;
    Clue *foundClue = searchClue(clueTree, searchId);
    if (foundClue != NULL) {
        printf("Pista #%d encontrada: [%s] %s\n", 
               foundClue->id, foundClue->category, foundClue->description);
    } else {
        printf("Pista #%d não encontrada\n", searchId);
    }
    
    // Display clues by category
    printf("\n--- Pistas Físicas ---\n");
    displayCluesByCategory(clueTree, "Física");
    
    // Remove a clue
    printf("\n--- Remoção de Pista ---\n");
    printf("Removendo pista #3...\n");
    clueTree = removeClue(clueTree, 3);
    printf("\nPistas restantes:\n");
    displayClues(clueTree);
    
    freeClues(clueTree);
}

void demonstrateSuspectLinks() {
    printSeparator();
    printf("=== VÍNCULOS PISTA-SUSPEITO (Tabela Hash) ===\n");
    printSeparator();
    
    HashTable *ht = createHashTable();
    
    // Link clues to suspects
    insertClueSuspect(ht, 2, "Sr. Johnson");
    insertClueSuspect(ht, 5, "Sra. Anderson");
    insertClueSuspect(ht, 7, "Sra. Anderson");
    insertClueSuspect(ht, 4, "Dr. Williams");
    insertClueSuspect(ht, 6, "Sr. Johnson");
    insertClueSuspect(ht, 8, "Mordomo James");
    
    // Display all links
    displayHashTable(ht);
    
    // Search for suspect linked to a clue
    printf("\n--- Busca de Suspeito ---\n");
    int clueId = 5;
    char *suspect = searchSuspect(ht, clueId);
    if (suspect != NULL) {
        printf("Pista #%d está vinculada a: %s\n", clueId, suspect);
    } else {
        printf("Nenhum suspeito vinculado à pista #%d\n", clueId);
    }
    
    // Remove a link
    printf("\n--- Remoção de Vínculo ---\n");
    removeClueSuspect(ht, 4);
    displayHashTable(ht);
    
    freeHashTable(ht);
}

void displayMenu() {
    printSeparator();
    printf("=== DETECTIVE QUEST - MENU PRINCIPAL ===\n");
    printSeparator();
    printf("1. Demonstrar Mapa da Mansão\n");
    printf("2. Demonstrar Organização de Pistas\n");
    printf("3. Demonstrar Vínculos Pista-Suspeito\n");
    printf("4. Executar Demonstração Completa\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int option;
    
    printf("\n");
    printf("╔════════════════════════════════════════════════╗\n");
    printf("║         BEM-VINDO AO DETECTIVE QUEST          ║\n");
    printf("║     Sistema de Gerenciamento de Evidências    ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    
    do {
        displayMenu();
        
        if (scanf("%d", &option) != 1) {
            // Clear input buffer on invalid input
            while (getchar() != '\n');
            option = -1;
        }
        
        switch (option) {
            case 1:
                demonstrateMansionMap();
                break;
            case 2:
                demonstrateClueOrganization();
                break;
            case 3:
                demonstrateSuspectLinks();
                break;
            case 4:
                demonstrateMansionMap();
                demonstrateClueOrganization();
                demonstrateSuspectLinks();
                break;
            case 0:
                printSeparator();
                printf("Encerrando o Detective Quest. Até logo!\n");
                printSeparator();
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
        if (option != 0 && option >= 1 && option <= 4) {
            printf("\nPressione Enter para continuar...");
            while (getchar() != '\n'); // Clear input buffer
            getchar(); // Wait for Enter
        }
        
    } while (option != 0);
    
    return 0;
}
