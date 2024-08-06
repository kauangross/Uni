#include <stdio.h>

void troca(int *c, int *d); // Protótipo

int main()
{
    int a = 5;
    int b = 10;

    troca(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

void troca(int *c, int *d)
{
    int aux = *c;
    *c = *d;
    *d = aux;
}