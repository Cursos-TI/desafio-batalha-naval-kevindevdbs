#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Char para o Cabeçalho de Colunas

    //Matriz para o tabuleiro

    int tabuleiro[11][11] = {
        {0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("---------------BATALHA NAVAL---------------\n\n");

    // Imprimir cabeçalho das colunas
    printf("    ");

    for (int j = 0; j < 10; j++) {
        printf(" %c ", linha[j]);
        
    }
    printf("\n");

    //Imprime o Tabuleiro

    for (int i = 1; i < 11; i++)
    {
        printf(" %2d ", i );

        for (int j = 1; j < 11; j++)
        {
           printf(" %d " , tabuleiro[i][j]);
        };

        printf("\n");
        
    }
    
    printf("\n");

     printf("---------------BATALHA NAVAL---------------\n\n");


    
    
    return 0;
}
