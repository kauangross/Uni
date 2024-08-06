#include <stdio.h>

void imprimirMatriz(int matrizz[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d ", matrizz[i][j]);
        printf("\n");
}

int main()
{
    int matriz[10][10];

    imprimirMatriz(matriz, 10, 10);

    return 0;
}