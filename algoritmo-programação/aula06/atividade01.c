#include <stdio.h>
#include <string.h>

// Funções
void menu()
{
    printf("\n");
    printf("_______________________________\n");
    printf("\n");
    printf("          CALCULADORA          \n");
    printf("_______________________________\n");
}

void sumario() 
{
    printf("\nDigite uma equacao com dois\nvalores e um operador somente.\n");
}

float multiplicacao(float n1, float n2) 
{
    return n1 * n2;
}

float divisao(float n1, float n2)
{
    return n1 / n2;
}

float soma(float n1, float n2)
{
    return n1 + n2;
}

float subtracao(float n1, float n2)
{
    return n1 - n2;
}

// Main
int main()
{
    float valor_1, valor_2, resultado;
    char operador;
    menu();
    do // While verificando no final
    {
        sumario();

        printf("\nDigite a operacao a seguir:\n");
        scanf("%f %c %f", &valor_1 , &operador, &valor_2);
        
        if (operador == '*')
        {
            multiplicacao(valor_1, valor_2);
            printf("Resultado: %.3f", multiplicacao(valor_1, valor_2));
        } else if (operador == '/')
        {
            resultado = divisao(valor_1, valor_2);
            printf("Resultado: %.3f", resultado);
        } else if (operador == '+')
        {
            resultado = soma(valor_1, valor_2);
            printf("Resultado: %.0f", resultado);
        } else if (operador == '-')
        {
            resultado = subtracao(valor_1, valor_2);
            printf("Resultado: %.0f", resultado);
        } else
        {
            printf("\nDigite uma opcao valida!\nApenas um operador de sinal e dois valores sao aceitos.");
        }
    } while (valor_1 != 0 && valor_2 != 0);
    return 0;
}