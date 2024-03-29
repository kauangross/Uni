#include <stdio.h>

int main()
{
    int sapatos;
    while (sapatos != 0) // Repete o algoritmo enquanto o numero de sapatos não for zero
    {
        // Número de sapatos
        printf("Numero de sapatos: ");
        scanf("%d", &sapatos);

        // Tamanho do sapato {37, 38, 39, 40, 41} referente ao num de sapatos definidos
        int tamanho[sapatos];
        // Lado do pé {E, D} referente ao num de sapatos definidos
        char lado[sapatos];
        // Número de pares completos
        int parcompleto = 0;
        
        // For para definir o tamanho e o lado dos sapatos
        for (int i = 0; i < sapatos; i++)
        {
            scanf("%d %c", &tamanho[i], &lado[i]);
        }

        // For dentro de outro for para passar por todos os sapatos
        for (int i = 0; i < sapatos; i++)
        {
            for (int j = (i+1); j < sapatos; j++)
            {
                if ((tamanho[i] == tamanho[j]) && ( lado[i] != lado[j])) // Verificador de sapatos complementares
                {
                    parcompleto++;
                }
            }
        }
        if (parcompleto == 1) // Imprime o num de pares completos
        {
            printf("%d par de sapatos completo\n", parcompleto); // 1 par completo
        } else {
            printf("%d pares de sapatos completos\n", parcompleto); // Mais de 1 par completo
        }
    }
    return 0;
}