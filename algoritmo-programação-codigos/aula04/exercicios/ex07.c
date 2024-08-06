#include <stdio.h>
#include <math.h>

int main()
{
    int num, quant, par, impar, soma = 0;
    while (num != 0)
    {
        printf("Digite um numero positivo: ");
        scanf("%d", &num);
        quant++; // Quantidade de números digitados
        soma = soma + num;
        if ((num % 2) == 0) // Número de pares
        {
            par++;
        } else // Número de ímpares
        {
            impar++;
        }
    }
    printf("Quantidade de numeros digitados: %d\n", quant);
    printf("Quantidade de numeros pares digitados: %d\n", par);
    printf("Quantidade de numeros impares digitados: %d\n", impar);
    printf("Soma dos numeros digitados: %d\n", soma);
    return 0;
}