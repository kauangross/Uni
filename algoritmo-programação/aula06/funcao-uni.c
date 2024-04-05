#include <stdio.h>

float media(float nota1, float nota2)
{
    nota1 *= 0.3;
    nota2 *= 0.7;
    return nota1 + nota2;
}

int main()
{
    float grau_a, grau_b;

    // Declaração
    printf("Digite a nota do grau a: ");
    scanf("%f", &grau_a);
    printf("Digite a nota do grau a: ");
    scanf("%f", &grau_b);

    // Chamada função
    float resultado = media(grau_a, grau_b);
    printf("Nota final: %.1f", resultado);

    return 0;
}
