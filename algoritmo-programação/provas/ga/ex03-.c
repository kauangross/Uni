#include <stdio.h>
#include <stdlib.h>

void menor_valor(int vetor[], int tamanho)
{ // [33, 54, 3, 19, 87]
    int aux;
    int pares[5];
    
    int x = 0;
    int y = 0;
    while (y < 5) // Copia o vetor, somente o indice par, para um vetor menor de 5 posições, que é a quantidade de indices pares no vetor principal. 
    {
        pares[y] = vetor[x];
        // printf("Vetor dos pares: %d \n", pares[y]);
        x += 2;
        y++;
    }
    for(int i = 0; i < 4; i++){ // Realoca o vetor dos pares de forma crescente
        for(int j = (i+1); j < 5; j++){
            if(pares[i] > pares[j]){
                aux = pares[i];
                pares[i] = pares[j];
                pares[j] = aux;
            }
        }
    }
    printf("Menor do indice par: %d\n", pares[0]); // Escreve a posição 0 do vetor (a menor)
}

void maior_valor(int vetor[], int tamanho)
{
    int aux;
    int impares[5];

    int x = 1;
    int y = 0;
    while (y < 5) // Copia o vetor, somente o indice par, para um vetor menor de 5 posições, que é a quantidade de indices pares no vetor principal. 
    {
        impares[y] = vetor[x];
        // printf("Vetor dos impares: %d \n", impares[y]);
        x += 2;
        y++;
    }
    for(int i = 0; i < 4; i++){ // Realoca o vetor dos impares de forma decrescente
        for(int j = (i+1); j < 5; j++){
            if(impares[i] < impares[j]){
                aux = impares[i];
                impares[i] = impares[j];
                impares[j] = aux;
            }
        }
    }
    printf("Maior do indice impar: %d", impares[0]);
}

void multiplicacao(int vetor[], int tamanho)
{
    
    float multiplicacao = 1;
    float somatorio;

    int tamanho_par = 0;
    int tamanho_impar = 0;
    for (int i = 0; i < tamanho; i++) // Declara o tamanho dos vetores pares e impares verificando cada posição do vetor
    {
        if (vetor[i] % 2 == 0) // Se for par, adiciona um ao tamamho
        {
            tamanho_par++;
        } else { // Se for impar, adiciona um ao tamanho dos impares
            tamanho_impar++;
        }
    }
    int vetorpar[tamanho_par]; /*= {8, 16, 54}*/
    int vetorimpar[tamanho_impar]; /*= {3, 5, 19, 33, 41, 87, 93}*/
    
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < tamanho) // Realoca os valores pares e impares do vetor principal nos vetores de pares e impares
    {
        if (vetor[i] % 2 == 0) // Se for par
        {
            vetorpar[j] = vetor[i];
            j++;
        } else { // Se for impar
            vetorimpar[k] = vetor[i];
            k++;
        }
        i++;
    }

    for(int i = 0; i < 3; i++) // Multiplica os falores pares
    {
        multiplicacao *= vetorpar[i];
    }
    for (int i = 0; i < 7; i++) // Faz a soma dos valores impares
    {
        somatorio += vetorimpar[i];
    }

    float resultado = multiplicacao / somatorio; // Resultado

    printf("\nDivisao final: %.4f\n", resultado);
}

int main()
{
    int vetor[10] = {33, 5, 54, 41, 3, 16, 19, 8, 87, 93};
    int tam = 10;

    menor_valor(vetor, tam);

    maior_valor(vetor, tam);

    multiplicacao(vetor, tam);

    return 0;
}