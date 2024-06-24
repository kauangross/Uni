#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int tam;

    printf("Qnt de numeros: ");
    scanf("%d", &tam);
    ptr = malloc(sizeof(int)*tam);
    if (ptr == NULL)
    {
        printf("Nao alocou");
        return 1;
    }
    
    for (int i = 0; i < tam; i++)
    {
        printf("Posicao[%d]: ", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = (tam-1); i >= 0; i--)
    {
        printf("Posicao[%d]: %d\n", i, ptr[i]);
    }
    
    free(ptr);
    return 0;
}
