#include <stdio.h>

int soma(int a, int b)
{
    return a + b;
}

int main()
{
    int num1 = 5;
    int num2 = 3;
    int resultado = soma(num1, num2);
    printf("A soma eh %d", resultado);
    return 0;
}