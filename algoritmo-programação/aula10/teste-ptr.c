#include <stdio.h>

int main()
{
    int a;
    int *ptr;

    a = 90;
    ptr = &a;

    printf("Valor de ptr: %p, Conteudo de ptr: %d", ptr, *ptr);
    return 0;
}
