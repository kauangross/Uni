#include <stdio.h>

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int v1 = 5;
    int v2 = 10;

    troca(&v1, &v2);
    printf("%d %d", v1, v2);
    return 0;
}
