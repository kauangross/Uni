#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2, delta, raizdelta;
    printf("\nFormula de Bhaskara: \n");

    printf("\n");

    printf("Digite os respectivos valores da equacao: \n");
    printf("a: ");
    scanf(" %f", &a);
    
    printf("b: ");
    scanf(" %f", &b);

    printf("c: ");
    scanf("%f", &c);
    
    delta = (b*b) + (-4*a*c);
    printf("\nO delta vale: %.2f \n", delta);

    if (delta < 1)
    {
        printf("\nPortanto, a equacao nao possui raizes reais!\n");
    }
    else 
    {
        raizdelta = (float)sqrt(delta);
        printf("A raiz de delta vale: %.2f \n", raizdelta);

        printf("\n");

        x1 = (-(b) + raizdelta)/(2*a);
        printf("\nO valor de x' vale: %.5f \n", x1); 
        
        x2 = (-(b) - raizdelta)/(2*a);
        printf("O valor de x'' vale: %.5f \n", x2);
        
        printf("\n");

        printf("\nS = {%f, %f}\n", x1, x2);  
    }

    printf("\n");
    return 0;
}