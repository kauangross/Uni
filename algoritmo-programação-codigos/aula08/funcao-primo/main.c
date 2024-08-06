#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(int num)
{
    if (num % 2 != 0)
    {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int n;
    int verificador;
    do
    {
        printf("Digite um numero positivo para verificar se eh primo: ");
        scanf("%d", &n);
        if (n != -1){
            verificador = primo(n);
            printf("%d", verificador);
        }
        if (verificador == 1){
            printf("\nPrimo\n");
        } else if(verificador == 0) {
            printf("\nNao eh primo\n");
        }
    } while (n != -1);


    return 0;
}
