#include <stdio.h>

int main()
{
    int res = 0;
    while (res != 3)
    {
        printf("MENU\n");
        printf("[1] Opcao 1\n");
        printf("[2] Opcao 2\n");
        printf("[3] Opcao sair do menu\n");
        
        printf("\nDigite a opcao: ");
        scanf("%d", &res);

        switch (res)
        {
        case 1:
            printf("\n[1] Opcao 1\n");
            break;
        case 2:
            printf("\n[2] Opcao 2\n");
            break;
        case 3:
            printf("\nSaindo do menu...\n");
            break; 
        default:
            printf("\bDigite um valor valido.\n");
        }
    }
    
    return 0;
}
