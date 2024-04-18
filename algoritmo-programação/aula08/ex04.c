#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void teste_rapido()
{
    char ns1, igm, igg;
    printf("Digite o resultado do teste NS1: ");
    scanf("%c", &ns1);
    printf("Digite o resultado do teste igm: ");
    scanf("%c", &igm);
    printf("Digite o resultado do teste igg: ");
    scanf("%c", &igg);

    printf("%c %c %c", ns1, igm, igg);
}

int main()
{
    int tempo;
    printf("Digite o tempo de doença: ");
    scanf("%d", &tempo);
    
    teste_rapido();

    /*
    if (tempo <= 6)
    {
        teste_rapido();
    } 
    */
       
    return 0;
}