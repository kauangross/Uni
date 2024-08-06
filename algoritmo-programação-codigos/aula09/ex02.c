#include <stdio.h>

#define lin 3
#define col 3

void busca(int l, int c, int mat[3][col], int valor)
{
    int encontrei = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == valor)
            {
                printf("\nEncontrei %d no indice [%d][%d]\n", mat[i][j], i, j);
                encontrei = 1;
                printf("\n");
            }
        }
    }
    if (encontrei == 0)
    {
        printf("\nNao encontrei\n");
    }
}

int main()
{
    int matriz[lin][col];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int v = 4;
    busca(lin, col, matriz, v);

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}