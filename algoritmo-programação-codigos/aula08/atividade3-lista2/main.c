#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[20];

    for(int i = 0; i < 20; i++)
    {
        if (i == 0){
            do
            {
                printf("Digite um numero positivo");
                scanf("&d", &vetor[i]);
            } while(vetor[i] < i);
        } else {
            do
            {
                printf("Digite um numero positivo");
                scanf("&d", &vetor[i]);
            }while (vetor[i] < i || vetor[i-1] > vetor[i]);
        }
    }
    return 0;
}
