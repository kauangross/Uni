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
    int n = 0;
    while (n >= 0)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &n);
        if (n >= 0)
        {
            verificador(n);
        }
    }
    return 0;
}
