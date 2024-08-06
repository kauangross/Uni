#include <stdio.h>
#include <math.h>

int main()
{
    int contador = 1;

    while (1)
    {
        int quadrado = pow(contador, 2);
        printf("O quadrado de %d eh %d\n", contador, quadrado);

        if (quadrado > 50) 
        {
            break;
        }
        contador++;
    }
    return 0;
}