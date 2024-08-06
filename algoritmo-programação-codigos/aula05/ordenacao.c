#include <stdio.h>

int main()
{
    int vetor[10] = {4, 1, 6, 2, 3, 9, 3, 6, 5, 10};
    int aux;

    for (int i = 0; i < 10; i++)
    {
         for (int j = (i+1); j < 9; j++)
         {
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
         }
         printf("%d ", vetor[i]);
    }
    return 0;
}