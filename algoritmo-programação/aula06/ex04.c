#include <stdio.h>

int funcao_primo(int num)
{
    if ( num % 2 != 0 ) // nao funciona
    {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int resp = 0;
    while (resp != -1)
    {
        printf("Digite um numero positivo: ");
        scanf("%d", &resp);
        funcao_primo(resp);
        printf("%d\n", funcao_primo(resp));
    }
    
    return 0;
}
