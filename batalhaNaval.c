#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Exibe o tabuleiro com valores numéricos (sem símbolos)
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("    ");
    for (int j = 1; j <= TAM; j++) {
        printf("%2d ", j);
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

// Cria a matriz Cone (5x5)
void criar_cone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria a matriz Cruz (5x5)
void criar_cruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Cria a matriz Octaedro (5x5) – forma de losango
void criar_octaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dist_i = i - 2;
            if (dist_i < 0) dist_i = -dist_i;
            int dist_j = j - 2;
            if (dist_j < 0) dist_j = -dist_j;

            if (dist_i + dist_j <= 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[TAM][TAM], int matriz[5][5], int origem_linha, int origem_coluna) {
    origem_linha--; // Ajuste para índice 0
    origem_coluna--;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int l = origem_linha + (i - 2);
            int c = origem_coluna + (j - 2);

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }
}

// Posiciona navios fixos no tabuleiro
void posicionar_navios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    for (int i = 0; i < 3; i++)
        tabuleiro[1][1 + i] = NAVIO;

    // Vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[4 + i][2] = NAVIO;

    // Diagonal principal
    for (int i = 0; i < 3; i++)
        tabuleiro[6 + i][6 + i] = NAVIO;

    // Diagonal secundária
    for (int i = 0; i < 3; i++)
        tabuleiro[6 + i][4 - i] = NAVIO;
}

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int cone[5][5], cruz[5][5], octaedro[5][5];

    posicionar_navios(tabuleiro);
    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);

    aplicar_habilidade(tabuleiro, cone, 3, 3);       // Cone em (3,3)
    aplicar_habilidade(tabuleiro, cruz, 6, 6);       // Cruz em (6,6)
    aplicar_habilidade(tabuleiro, octaedro, 8, 3);   // Octaedro em (8,3)

    exibir_tabuleiro(tabuleiro);
    return 0;
}
