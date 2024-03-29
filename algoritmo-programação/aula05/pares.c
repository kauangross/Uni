#include <stdio.h>

int main()
{
    int n;
    printf("Digite o valor inicial: ");
    scanf("%d", &n);
    while (n >= 2)
    {
        if ((n % 2) == 0)
        {
            printf("%d.. ", n);
        }
        n--;
    }
    return 0;
}