#include <stdio.h>
#include <math.h>

void ehpositivo(int a, int b, int c)
{
    int x1, x2;
    int delta = (pow(b, 2) + (-4 * a * c));
    printf("Delta: %d", delta);
    if ( delta > 0 )
    {
        printf("\nO delta eh positivo, possui duas raizes:\n");
        x1 = (-(b) + sqrt(delta)) / (2 * a);
        x2 = (-(b) - sqrt(delta)) / (2 * a);
        printf("x'= %d\n", x1);
        printf("x''= %d", x2);
    } else if ( delta == 0 )
    {
        printf("\nO delta eh zero, possui uma raiz:\n");
        x1 = (-(b)) / (2 * a);
        printf("%d", x1);
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
