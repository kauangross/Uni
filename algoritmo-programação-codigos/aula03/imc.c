#include <stdio.h>

int main()
{
    float imc, peso, altura;
    printf("\nDigite seu peso: ");
    scanf("%f", &peso);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    imc = (peso)/(altura*altura);
    printf("IMC: %f\n", imc);

    if (imc < 18.5)
    {
        printf("\nVoce esta abaixo do peso ideal!\n");
    } else if (imc < 25)
    {
        printf("\nVoce esta no peso ideal!\n");
    } else {
        printf("\nVoce esta acima do peso ideal!\n");
    }

    return 0;
}
