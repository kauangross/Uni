#include <stdio.h>

int main()
{
    int n;
    int soma = 0;

    printf("DIgite um numero positivo: ");
    scanf("%d", &n);
    
    while (n > 0)
    {
        soma += n % 10;
        n /= 10;
    }
    
    printf("%d\n", soma);
    return 0;
}
