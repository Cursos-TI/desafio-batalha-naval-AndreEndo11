#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_CONE 5
#define TAMANHO_CRUZ 5
#define TAMANHO_OCTAEDRO 5

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

void habilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna < TAMANHO_CONE <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_CONE; i++) {
                tabuleiro[linha][coluna + i] = 5; // Posicionando habilidade cone na horizontal
            }
        }
    } else {
        if (linha < TAMANHO_CONE <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_CONE; i++) {
                tabuleiro[linha + i][coluna] = 5; // Posicionando habilidade cone na vertical
            }
        }
    }
}

void habilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna < TAMANHO_CRUZ <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_CRUZ; i++) {
                tabuleiro[linha][coluna + i] = 5; // Posicionando habilidade cruz na horizontal
            }
        }
    } else {
        if (linha < TAMANHO_CRUZ <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_CRUZ; i++) {
                tabuleiro[linha + i][coluna] = 5; // Posicionando habilidade cruz na vertical
            }
        }
    }
}

void habilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna < TAMANHO_OCTAEDRO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_OCTAEDRO; i++) {
                tabuleiro[linha][coluna + i] = 5; // Posicionando habilidade octaedron na horizontal
            }
        }
    } else {
        if (linha < TAMANHO_OCTAEDRO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_OCTAEDRO; i++) {
                tabuleiro[linha + i][coluna] = 5; // Posicionando habilidade octaedro na verticalmente
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
    int option;
    // Enquanto a option for 1 ou 2 o jogo continua, quando option for 3 sai do jogo.
    do {
        printf("### JOGO BATALHA NAVAVAL ###\n");
        printf("Menu:\n");
        printf("1. Posicionar navios! \n");
        printf("2. Habilidades! \n");
        printf("3. Sair...!\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &option);
        
        printf("\n");
        switch(option) {
            case 1:
                printf("###### START ######\n");
                int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

                inicializarTabuleiro(tabuleiro);

                // Definição das coordenadas iniciais dos navios
                posicionarNavio(tabuleiro, 2, 3, 1); // Navio horizontal começando na linha 2, coluna 3
                posicionarNavio(tabuleiro, 5, 6, 0); // Navio vertical começando na linha 5, coluna 6             
                exibirTabuleiro(tabuleiro);

                printf("\n");
                break;
            case 2:
                printf("###### START ######\n");

                inicializarTabuleiro(tabuleiro);
                // Definição das coordenadas iniciais das habilidades
                habilidadeCone(tabuleiro, 7, 0, 1); // Coordenadas do CONE LINHA
                tabuleiro[6][1] = 5;
                tabuleiro[6][2] = 5;
                tabuleiro[6][3] = 5;
                tabuleiro[5][2] = 5;
                habilidadeCruz(tabuleiro, 2, 1, 1); // Coordenadas da CRUZ LINHA
                habilidadeCruz(tabuleiro, 0, 3, 0); // Coordenadas da CRUZ COLUNA
                
                habilidadeOctaedro(tabuleiro, 5, 5, 1); // Coordenadas do OCTAEDRO LINHA
                habilidadeOctaedro(tabuleiro, 3, 7, 0); // Coordenadas do OCTAEDRO COLUNA
                tabuleiro[6][6] = 5;
                tabuleiro[6][8] = 5;
                tabuleiro[4][6] = 5;
                tabuleiro[4][8] = 5;
                exibirTabuleiro(tabuleiro);

                printf("\n");
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 3);

    return 0;

}
