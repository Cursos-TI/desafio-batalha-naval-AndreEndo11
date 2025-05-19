#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Inicializando todas as posições com água (0)
        }
    }
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = 3; // Posicionando navio horizontalmente
            }
        }
    } else {
        if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = 3; // Posicionando navio verticalmente
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibindo cada posição do tabuleiro
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Definição das coordenadas iniciais dos navios
    posicionarNavio(tabuleiro, 2, 3, 1); // Navio horizontal começando na linha 2, coluna 3
    posicionarNavio(tabuleiro, 5, 6, 0); // Navio vertical começando na linha 5, coluna 6

    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
