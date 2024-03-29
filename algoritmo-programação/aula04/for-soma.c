#include <stdio.h>

int main()
{
    int soma;
    for (int i = 0; i <= 10; i++)
    {
        soma += i;
    }
    printf("%d", soma);
    return 0;
}