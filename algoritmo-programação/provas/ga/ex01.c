#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ini, fim, qt;
    printf("Digite o valor inicial: ");
    scanf("%f", &ini);

    printf("Digite o valor final: ");
    scanf("%f", &fim);

    printf("Digite a quantidade desejada: ");
    scanf("%f", &qt);

    // an = a1 + (n-1) x r
    float r = (fim - ini) / (qt-1); // razao da P.A

    for(int i = 0; i < qt; i++) // for que calcula e mostra na tela os valores da P.A
    {
        printf("%.2f ", ini);
        ini = ini + r;
    }
    return 0;
}