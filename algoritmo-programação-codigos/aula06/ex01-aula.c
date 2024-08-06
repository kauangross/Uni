#include <stdio.h>

void verificador(int num)
{
    if (num % 2 == 0)
    {
        printf("PAR\n");
    } else {
        printf("IMPAR\n");
    }
}

int main()
{
    int n;

    while (1)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &n);
        verificador(n);
        if (n < 0)
        {
            break;
        }
    }
    return 0;
}