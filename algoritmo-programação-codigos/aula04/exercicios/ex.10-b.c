#include <stdio.h>

int main()
{
   /*
        for (int h = 0; h <= i; h++)
        {
            printf(" ");
        }
   */
   printf("\n");
   int linha;
   printf("Quantas linhas deseja imprimir? ");
   scanf("%d", &linha);
   for (int i = 0; i < linha; i++)
   {
        for (int h = 0; h < i; h++)
        {
            printf(" ");
        }
        
        for (int j = 0; j <  (linha - i); j++)
        {
            printf("* ");
        }
        printf("\n");
   }
    return 0;
}