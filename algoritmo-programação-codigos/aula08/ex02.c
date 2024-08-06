#include <stdio.h>

void ordenador(int vetor[], int tam)
{
    int aux;
    for (int i = 0; i < tam; i++)
    {
        for (int j = (i+1); j < tam; j++)
        {
            if (vetor[i] < vetor[j])
            {
                aux = vetor[i];
                vetor [i] = vetor[j];
                vetor[j] = aux;
            }
        }
        printf("%d", vetor[i]);
    } 
}

int main()
{
    int n;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }   
    
    ordenador(vetor, n);

    return 0;
}
