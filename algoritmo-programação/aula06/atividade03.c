#include <stdio.h>
#include <math.h>

void ehpositivo(int x, int y, int z)
{
    int delta = (pow(y, 2) + (-4 * x * z));
    printf("Delta: %d", delta);
    if ( delta > 0 )
    {
        printf("\nO delta eh positivo\n");
    } else if ( delta == 0 )
    {
        printf("\nO delta eh positivo.\n");
    } else 
    {
        printf("\nO delta eh negativo. Nao possui raies reais.\n");
    }
}

int main()
{
    int a, b, c;
    printf("Digite os parametros (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);

    ehpositivo(a, b, c);

    return 0;
}
