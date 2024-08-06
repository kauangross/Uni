#include <stdio.h>

int fatorial(int n) // Operação fatorial
{
    int resultado = 1;
    for (int i = 1; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}

int main()
{
    int num = 5;
    int fat = fatorial(num);
    printf("O fatorial de 5 eh: %d\n", fat);

    fat = fatorial(6);
    printf("O fatorial de 6 eh: %d\n", fat);

    return 0;
}
