#include <stdio.h>

void soma(int *a, int *b, int *c)
{
    *c = *a + *b;
}

int main()
{
    int v1 = 5;
    int v2 = 10;
    int v3;
    
    soma(&v1, &v2, &v3);
    printf("%d", v3);
    return 0;
}
