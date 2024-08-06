#include <stdio.h>

int ehpositivo(int n)
{
    if (n >= 0)
    {
        return 1; // True (positivo)
    } else
    {
        return 0; // False (negativo)
    }
}

int main()
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);
    
    ehpositivo(num);
    printf("%d", ehpositivo(num));
    return 0;
}
