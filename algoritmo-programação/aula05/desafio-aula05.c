#include <stdio.h>

int main()
{
    int sapatos;
    while (sapatos != 0) // Repete o algoritmo enquanto o numero de sapatos não for zero
    {
        // Número de sapatos
        printf("Numero de sapatos: ");
        scanf("%d", &sapatos);

        if (sapatos % 2 == 0) // Se for par, continua
        {
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
                    if ((tamanho[i] == tamanho[j]) && (lado[i] != lado[j])) // Verificador de sapatos complementares
                    {
                        parcompleto++;
                        lado[j] = 'f'; // Adiciono outro valores para as variáveis, assim, o sapato que já faz parte de um par, não é testado com outro sapato
                        lado[i] = 'f';
                        tamanho[i] = 0;
                        tamanho[j] = 0;
                    }
                }
            }

            if (parcompleto == 1) // Imprime o num de pares completos
            {
                printf("%d par de sapato completo\n", parcompleto); // 1 par completo
            } else {
                printf("%d pares de sapatos completos\n", parcompleto); // Mais de 1 par completo
            }  
        } else { // Se não for par, repete até ser
            printf("Digite um numero par...\n");
        }
    }
    return 0;
}