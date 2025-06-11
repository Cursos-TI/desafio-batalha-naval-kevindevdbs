#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0

// Função para verificar se é possível posicionar um navio
int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    linha--; // Ajustar para índice da matriz (0-9)
    coluna--;

    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l = linha + i;
            c = coluna + i;
        } else if (diagonal == 2) {
            l = linha + i;
            c = coluna - i;
        } else if (direcao == 0) {
            c = coluna + i;
        } else if (direcao == 1) {
            l = linha + i;
        }

        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != AGUA) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    linha--; coluna--; // Ajustar índice

    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l = linha + i;
            c = coluna + i;
        } else if (diagonal == 2) {
            l = linha + i;
            c = coluna - i;
        } else if (direcao == 0) {
            c = coluna + i;
        } else if (direcao == 1) {
            l = linha + i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro (de 1 a 10)
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("    ");
    for (int i = 1; i <= TAM; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Coordenadas de 1 a 10 
    if (pode_posicionar(tabuleiro, 1, 1, 0, 0)) { // Horizontal
        posicionar_navio(tabuleiro, 1, 1, 0, 0);
    }

    if (pode_posicionar(tabuleiro, 5, 2, 1, 0)) { // Vertical
        posicionar_navio(tabuleiro, 5, 2, 1, 0);
    }

    if (pode_posicionar(tabuleiro, 3, 3, 0, 1)) { // Diagonal principal
        posicionar_navio(tabuleiro, 3, 3, 0, 1);
    }

    if (pode_posicionar(tabuleiro, 6, 8, 0, 2)) { // Diagonal secundária
        posicionar_navio(tabuleiro, 6, 8, 0, 2);
    }

    exibir_tabuleiro(tabuleiro);

    return 0;
}
