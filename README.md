# Detective Quest

Um jogo de detetive desenvolvido em C que implementa estruturas de dados avançadas para gerenciar o mapa da mansão, organizar pistas e vincular evidências a suspeitos.

## 📋 Estruturas de Dados Implementadas

### 1. Árvore Binária (Binary Tree)
- **Propósito**: Armazena o mapa da mansão
- **Funcionalidades**:
  - Criação de cômodos com nome e descrição
  - Navegação entre cômodos (esquerda/direita)
  - Busca de cômodos específicos
  - Visualização hierárquica do mapa

### 2. Árvore de Busca Binária (BST)
- **Propósito**: Organiza pistas de forma categórica
- **Funcionalidades**:
  - Inserção de pistas com ID, categoria e descrição
  - Busca eficiente de pistas por ID
  - Remoção de pistas
  - Exibição ordenada de pistas
  - Filtro de pistas por categoria

### 3. Tabela Hash (Hash Table)
- **Propósito**: Vincula pistas a suspeitos
- **Funcionalidades**:
  - Inserção de vínculos pista-suspeito
  - Busca rápida de suspeitos por ID de pista
  - Remoção de vínculos
  - Tratamento de colisões por encadeamento

## 🚀 Como Compilar e Executar

### Compilação
```bash
make
```

### Executar o programa
```bash
make run
```

### Limpar arquivos compilados
```bash
make clean
```

## 🎮 Como Usar

O programa apresenta um menu interativo com as seguintes opções:

1. **Demonstrar Mapa da Mansão**: Mostra a estrutura da mansão e permite navegar entre os cômodos
2. **Demonstrar Organização de Pistas**: Exibe como as pistas são organizadas e buscadas
3. **Demonstrar Vínculos Pista-Suspeito**: Mostra como pistas são vinculadas a suspeitos
4. **Executar Demonstração Completa**: Executa todas as demonstrações em sequência
0. **Sair**: Encerra o programa

## 📁 Estrutura do Projeto

```
detective_quest/
├── binary_tree.h       # Header da árvore binária
├── binary_tree.c       # Implementação da árvore binária
├── bst.h              # Header da árvore de busca
├── bst.c              # Implementação da árvore de busca
├── hash_table.h       # Header da tabela hash
├── hash_table.c       # Implementação da tabela hash
├── main.c             # Programa principal
├── Makefile           # Arquivo de compilação
└── README.md          # Este arquivo
```

## 🔧 Recursos da Linguagem C Utilizados

- **Variáveis**: Tipos básicos e derivados
- **Structs**: Definição de estruturas complexas
- **Operadores**: Aritméticos, relacionais e lógicos
- **Condicionais**: if-else, switch-case
- **Estruturas aninhadas**: Structs dentro de structs
- **Funções de entrada e saída**: printf, scanf
- **Alocação dinâmica**: malloc, free
- **Ponteiros**: Manipulação de memória e estruturas encadeadas
- **Recursão**: Para percorrer árvores

## 📝 Funcionalidades Implementadas

✅ Inserção de elementos nas três estruturas de dados  
✅ Busca eficiente de elementos  
✅ Remoção de elementos  
✅ Organização categórica de dados  
✅ Visualização formatada de informações  
✅ Gerenciamento apropriado de memória  
✅ Interface interativa via menu  

## 🎯 Conceitos de Estruturas de Dados

- **Árvore Binária**: Cada nó tem no máximo dois filhos
- **BST**: Propriedade de ordenação (esquerda < raiz < direita)
- **Tabela Hash**: Acesso O(1) médio com função hash
- **Encadeamento**: Resolução de colisões na tabela hash
- **Travessia em ordem**: Para exibir elementos ordenados
- **Alocação dinâmica**: Estruturas flexíveis e eficientes