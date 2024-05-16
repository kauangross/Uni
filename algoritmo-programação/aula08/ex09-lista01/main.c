#include <stdio.h>
#include <stdlib.h>

int calculo(int moeda[])
{
    int soma = 0;
    printf("Digite o numero de moedas de 1, 5, 10, 25, 50, respectivamente:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Quantidade: ");
        scanf("%d", &moeda[i]);
        if (i == 0){
            soma += moeda[i];
        } else if (i == 1){
            soma += moeda[i] * 5;
        } else if (i == 2){
            soma += moeda[i] * 10;
        } else if (i == 3){
            soma += moeda[i] * 25;
        } else {
            soma += moeda[i] * 50;
        }
    }
    return soma;
}


int main()
{
    int moeda[5];
    // 0 = 1, 1 = 5, 2 = 10, 3 = 25, 4 = 50

    int soma_main = calculo(moeda);

    printf("%d", soma_main);
    return 0;
}
