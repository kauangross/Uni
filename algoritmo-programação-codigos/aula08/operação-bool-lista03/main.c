#include <stdio.h>
#include <stdlib.h>

float salario(float *salario1, float *salario2)
{
    float salarioo = *salario2 / *salario1;
    *salario2 *= 2;
    *salario1 *= 2;
    return salarioo;
}

int main()
{
    float salario_m, salario_f, salario_quant;
    printf("DIgite o valor do salario minimo: ");
    scanf("%f", &salario_m);
    printf("DIgite o valor do seu salario: ");
    scanf("%f", &salario_f);

    salario_quant = salario(&salario_m, &salario_f);

    printf("Voce recebe %f salarios minimos", salario_quant);
    printf("\nTeste passagem por referencia.\nsalario min na funcao: %f\nsalario funcionario na funcao: %f", salario_m, salario_f);
    return 0;
}
