#include <stdio.h>
#include <stdlib.h>

float soma_inversa(int n)
{
    float soma;
    for(float i = 1; i <= n; i++) {
        soma += (1 / i);
    }

    return soma;
}

int main()
{
    int n;
    while (n != -1)
    {
        printf("Digite um numero inteiro de 1 a 9: ");
        scanf("%d", &n);
        if (n >= 1 && n <= 9)
        {
            float valor = soma_inversa(n);
            printf("Valor da soma: %f\n", valor);
        } else if (n == -1) { // se for -1, aparece a mensagem de fechamento
            printf("Saindo...\n");
        } else { // Qualquer outro valor fora das opcoes, nao realiza nada e sai
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
