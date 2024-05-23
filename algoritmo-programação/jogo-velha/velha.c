#include <stdio.h>

int main()
{
    int vetor[3][3] = { 1, 2, 3,
                        4, 5, 6,
                        7, 8, 9 };
    int velha, vitoria = 0;
    int aux;
    int contador;

    while (velha |= 1 || vitoria != 1)
    {
        int i = 0;
        while (i < 3)
        {   
            int j = 0;
            while (j < 3)
            {
                if (j == 0 || j == 1)
                {
                    if (vetor[i][j] == 0 || vetor[i][j] == 10)
                    {
                        printf(" X |");
                        contador++;
                        vetor[i][j] = 10;
                    } else
                        printf(" %d |", vetor[i][j]);
                } else if (j == 2)
                {
                    if (vetor[i][j] == 0 || vetor[i][j] == 10)
                    {
                        printf(" X ");
                        contador++;
                        vetor[i][j] = 10;
                    } else
                        printf("%d ", vetor[i][j]);
                } 
                j++;
            }
            printf("\n --|---|--\n");
            i++;
        }
        printf("\nCont: %d\n", contador);
        if (contador == 9)
        {
            printf("\nFim de jogo: VELHA\n");
        }

        printf("Vez do X: ");
        scanf("%d", &aux);
    
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (aux == (vetor[i][j]))
                {
                    vetor[i][j] = 0;
                }
            }
        }
    }

    return 0;
}
