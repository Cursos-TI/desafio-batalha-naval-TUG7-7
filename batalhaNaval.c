#include <stdio.h>
#include <stdlib.h>  // Necessário para usar a função abs() em C

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

 // Declaração da matriz 10x10 representando o tabuleiro
    int tabuleiro[10][10];

      // Variáveis para coordenadas iniciais dos navios
    int linhaHorizontal = 2;  // linha inicial do navio horizontal
    int colunaHorizontal = 4; // coluna inicial do navio horizontal
    int linhaVertical = 5;    // linha inicial do navio vertical
    int colunaVertical = 7;   // coluna inicial do navio vertical

     // Variáveis para navios diagonais (nível aventureiro)
    int linhaDiagonal1 = 0;   // linha inicial do navio diagonal principal (↘)
    int colunaDiagonal1 = 0;  // coluna inicial do navio diagonal principal (↘)
    int linhaDiagonal2 = 0;   // linha inicial do navio diagonal secundário (↙)
    int colunaDiagonal2 = 9;  // coluna inicial do navio diagonal secundário (↙)

    // Tamanho fixo dos navios (3 posições)
    int tamanhoNavio = 3;

    // ---------- Inicialização do Tabuleiro ----------
    // Preenche todas as posições com 0 (representa água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // ---------- Interação com o Usuário ----------
    printf("=== POSICIONAMENTO DOS NAVIOS ===\n");
    printf("Digite a linha e a coluna iniciais do navio HORIZONTAL (0 a 9): ");
    scanf("%d %d", &linhaHorizontal, &colunaHorizontal);

    printf("Digite a linha e a coluna iniciais do navio VERTICAL (0 a 9): ");
    scanf("%d %d", &linhaVertical, &colunaVertical);

    // Interação adicional para o nível aventureiro
    printf("Digite a linha e a coluna iniciais do navio DIAGONAL PRINCIPAL (↘) (0 a 9): ");
    scanf("%d %d", &linhaDiagonal1, &colunaDiagonal1);

    printf("Digite a linha e a coluna iniciais do navio DIAGONAL SECUNDÁRIA (↙) (0 a 9): ");
    scanf("%d %d", &linhaDiagonal2, &colunaDiagonal2);

      // ---------- Posicionamento do Navio Horizontal ----------
    // O navio ocupa 3 colunas na mesma linha
    for (int i = 0; i < tamanhoNavio; i++) {
        if (colunaHorizontal + i < 10) // garante que o navio cabe no tabuleiro
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }
    // ---------- Posicionamento do Navio Vertical ----------
    // O navio ocupa 3 linhas na mesma coluna
    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaVertical + i < 10) // garante que o navio cabe no tabuleiro
            tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // ---------- Posicionamento do Navio Diagonal Principal (↘) ----------
    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaDiagonal1 + i < 10 && colunaDiagonal1 + i < 10)
            tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
    }

     // ---------- Posicionamento do Navio Diagonal Secundária (↙) ----------
    for (int i = 0; i < tamanhoNavio; i++) {
        if (linhaDiagonal2 + i < 10 && colunaDiagonal2 - i >= 0)
            tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3;
    }

     // ---------- Exibição do Tabuleiro ----------
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    printf("Navio Horizontal: linha %d, coluna %d\n", linhaHorizontal, colunaHorizontal);
    printf("Navio Vertical: linha %d, coluna %d\n", linhaVertical, colunaVertical);
    printf("Navio Diagonal ↘: linha %d, coluna %d\n", linhaDiagonal1, colunaDiagonal1);
    printf("Navio Diagonal ↙: linha %d, coluna %d\n", linhaDiagonal2, colunaDiagonal2);

  // ---------- Interação após a Exibição ----------
    int opcaoHabilidade;
    printf("\nEscolha uma habilidade para aplicar:\n");
    printf("1 - Cone\n2 - Cruz\n3 - Octaedro\n");
    printf("Opção: ");
    scanf("%d", &opcaoHabilidade);

    // ---------- Nível Mestre - Habilidades Especiais ----------
    int habilidade[5][5];

    // Preenche a matriz de habilidade conforme a escolha
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            habilidade[i][j] = 0;

            if (opcaoHabilidade == 1) { // Cone
                if (i >= j - 2 && i >= 2 - j) habilidade[i][j] = 1;
            } else if (opcaoHabilidade == 2) { // Cruz
                if (i == 2 || j == 2) habilidade[i][j] = 1;
            } else if (opcaoHabilidade == 3) { // Octaedro
                if (abs(i - 2) + abs(j - 2) <= 2) habilidade[i][j] = 1;
            }
        }
    }

    // Define ponto de origem no tabuleiro (centro aproximado)
    int origemLinha = 4;
    int origemColuna = 4;

    // Sobrepõe a habilidade ao tabuleiro (marca com 5)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - 2);
                int colunaTab = origemColuna + (j - 2);
                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    // Exibe o tabuleiro atualizado com a habilidade
    printf("\n=== TABULEIRO COM HABILIDADE ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n");




    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
