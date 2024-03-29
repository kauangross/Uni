#include <stdio.h>

int main()
{
    int cont = 1;
    int fatorial = 1;
    int n;
    scanf("%d", &n);
    while (cont <= n)
    {
        if (cont < n)
        {
            printf("%d * ", cont);
        } else
        {
            printf("%d: ", cont);
        }

        fatorial = fatorial * cont;
        cont++;
    }
    printf("%d", fatorial);
    return 0;
}