#include <stdio.h>
#include <stdlib.h>

void ordenador(int lista[], int tam)
{
    for(int i = 0; i < (tam-1); i++){
        for(int j = (i+1); j < tam; j++){
            if (lista [i] < lista[j]){
                int aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    for(int i = 0; i < tam; i++){
        printf("%d", lista[i]);
    }
}


int main()
{
    int tam;
    printf("Qual o tamanho da lista? ");
    scanf("%d", &tam);

    int lista[tam];
    for(int i = 0; i < tam; i++){
        printf("Digite o valor da posicao %d da lista: ", i+1);
        scanf("%d", &lista[i]);
    }

    ordenador(lista, tam);

    return 0;
}
