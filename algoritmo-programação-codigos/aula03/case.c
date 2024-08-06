#include <stdio.h>

int main()
{
    int opcao = 4;
    printf("Escolha a opcao:\n");
    printf("Caso 1\n");
    printf("Caso 2\n");
    printf("Caso 3\n");
    while (opcao > 3)
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Voce escolheu a opcao 1.\n");
            break;
        case 2:
            printf("Voce escolheu a opcao 2.\n");
            break;
        case 3:
            printf("Voce escolheu a opcao 3.\n");
            break;
        default:
            printf("Escolha de 1 a 3.\n");
            break;
        }
    }
    return 0;
}
