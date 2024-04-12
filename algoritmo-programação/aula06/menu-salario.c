#include <stdio.h>

void menu()
{
    printf("\n                    MENU\n");
    printf("--------------------------------------------------\n");
    printf("[1] Salario bruto\n");
    printf("[2] Quanto pagou ao INSS\n");
    printf("[3] Quanto pagou ao SINDICATO\n");
    printf("[4] Salario liquido\n");
    printf("[5] Relatorio Geral\n");
    printf("[6] Sair\n");
}

float op02(float s)
{
    float conta = (s * 0.11); 
    return conta;
}

float op03(float s)
{
    float conta = (s * 0.02); 
    return conta;
}

float op04(float s)
{
    float conta = s - (op02(s) + op03(s));
    return conta;
}

void op05(float s_bruto)
{
    printf("----------------RELATORIO COMPLETO-----------------\n");
    printf("Seu salario bruto mensal: %.2f\n", s_bruto);
    printf("Pagou %.2f ao INSS\n", op02(s_bruto));
    printf("Pagou %.2f ao Sindicato\n", op03(s_bruto));
    printf("Salario liquido: %.2f\n", op04(s_bruto));
}

int main()
{
    /*
        while != 5
        case - 5 opc.
        fun
    */
    float s;
    float horas;
    int res;
    float s_bruto;
    float INSS;
    float Sindicato;
    float s_liquido;

    printf("Digite o valor que voce ganha por hora: ");
    scanf("%f", &s);
    printf("Digite o numero de horas trabalhadas no mes: ");
    scanf("%f", &horas);
    s_bruto = (s * horas); // Salário Bruto
    do
    {
        if (s > 0 && horas > 0)
        {
            menu();
            scanf("%d", &res);
            printf("\n");
            switch (res)
            {
            case 1:
                printf("Seu salario bruto mensal: %.2f\n", s_bruto);
                break;
            case 2:
                INSS = op02(s_bruto);
                printf("Pagou %.2f ao INSS\n", INSS);
                break;
            case 3:
                Sindicato = op03(s_bruto);
                printf("Pagou %.2f ao Sindicato\n", Sindicato);
                break;
            case 4:
                s_liquido = op04(s_bruto);
                printf("Salario liquido: %.2f\n", s_liquido);
                break;
            case 5:
                op05(s_bruto);
                break;
            case 6:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Digite uma opcao de 1 a 6.");
                break;
            }
        } else {
            printf("Dados insuficientes.\n");
            printf("\n");

            printf("Digite novamente o valor que voce ganha por hora: ");
            scanf("%f", &s);
            printf("Digite novamente o numero de horas trabalhadas no mes: ");
            scanf("%f", &horas);
            s_bruto = (s * horas);
        }
    } while (res != 6);
    return 0;
}
