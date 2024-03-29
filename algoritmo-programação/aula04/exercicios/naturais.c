#include <stdio.h>

int main()
{
    int cont = 1;
    int n;
    scanf("%d", &n);
    while (cont <= n)
    {
        printf("%d ", cont);
        cont = cont + 2;
    }
    return 0;
}