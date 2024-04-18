#include <stdio.h>
#include <math.h>

void calculo(float al, float pe)
{
    float imc;
    imc = pe/ pow(al, 2);
    printf("Seu IMC: %f\n", imc);
    
    if (imc < 18.5)
    {
        printf("Voce esta abaixo do peso");
    } else if (imc >= 18.5 && imc <= 24.9)
    {
        printf("Voce esta no peso normal");
    } else if (imc >= 25 && imc <= 29.9)
    {
        printf("Acima do peso");
    } else if (imc >= 30 && imc <= 34.9)
    {
        printf("Obesidade grau 1");
    } else if (imc >= 35 && imc <= 39.9) 
    {
        printf("Obesidade grau 2");
    } else
    {
        printf("Obesidade grau 3");
    }
    

    
    
    
    
    
}

int main()
{
    float altura, peso;
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("Digite sua peso: ");
    scanf("%f", &peso);

    calculo(altura, peso);

    return 0;
}
