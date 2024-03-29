#include <stdio.h>

int main()
{
    // Número de colunas que deseja
    int linhas = 3;
    // Números de linhas que deseja
    int colunas = 3;

    // i <= ao número de linhas que declarou
    for (int i = 1; i <= linhas; i++)
    {
    // j <= ao número de colunas que declarou
        for (int j = 1; j <= colunas; j++)
        {
            printf("%d%d ", i, j);
        }
        printf("\n");
    }
    
}