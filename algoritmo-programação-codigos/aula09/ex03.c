#include <stdio.h>

#define lin 3
#define col 3

void soma(int matA[lin][col], int matB[lin][col], int result[lin][col])
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matA[i][j] + matB[i][j];
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int matrizA[lin][col];
    int matrizB[lin][col];
    int resultado[lin][col];

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    soma(matrizA, matrizB, resultado);

    printf("Matriz completa:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz diagonal principal:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                printf("%d ", resultado[i][j]);
            }
            printf("   ");
        }
        printf("\n");
    }
    /*
    for (int i = 0; i < lin; i++)
    {
        printf("%d ", resultado[i][i]);
        printf("\n");
    }
    }*/
    return 0;
}