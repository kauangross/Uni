#include <stdio.h>

int main()
{
   int linha;
   printf("Quantas linhas deseja imprimir? ");
   scanf("%d", &linha);
   for (int i = 0; i < linha; i++)
   {
        for (int j = 0; j <  (linha - i); j++)
        {
            printf("* ");
        }
        printf("\n");
   }
    return 0;
}