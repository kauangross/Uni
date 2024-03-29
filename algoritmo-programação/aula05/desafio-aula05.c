#include <stdio.h>

int main()
{
    /*
        1 - inteiro n = numero de botas individuais
        n linhas - = uma bota ( inteiro M e uma letra L )
                                m = tamanho     l = lado da bota 

        saida :
        numero total de pares corretos
    */

    // Número de sapatos
    int sapatos = 4;

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
    printf("%d", parcompleto);

    return 0;
}