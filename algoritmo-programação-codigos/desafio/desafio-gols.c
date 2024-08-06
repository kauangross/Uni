#include <stdio.h>

int main()
{
    int lin, col; // Jogadores, jogos
    int cont, zero = 0;

    while ((lin < 1 || lin > 100) && (col < 1 || col > 100)) // Questiona o tamanho da matriz
    {
        printf("Digite o num de jogadores e de jogos: ");
        scanf("%d %d", &lin, &col);
    }

    int gols[lin][col];

    for (int i = 0; i < lin; i++) // Adiciona os valores a matriz
    {
        printf("Jogador[%d]: ", i);
        for (int j = 0; j < col; j++)
        {
            do {
                scanf("%d", &gols[i][j]);
            } while (gols[i][j] < 0 || gols[i][j] > 100); // Repete enquanto o numero de gols for maior que cem e menor que zero
        }
        printf("\n");
    }

    for (int i = 0; i < lin; i++) // Verifica se existe um zero na linha
    {
        for (int j = 0; j < col; j++)
        {
            if (gols[i][j] == 0) // Se existir zero, adiciona um a variavel e quebra o laço, pulando de linha
            {
                zero++;
                break;;
            }
        }
        printf("\n");
    }
    cont += (lin - zero); // Desconta o numero de linhas com zero da variavel que contem o numero de linhas = numero de linhas que não contém zeros
    
    //printf("%d", zero);
    printf("\nContador de jogares que fizeram gols em todas as partidas: %d", cont);
    return 0;
}