#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void teste_rapido()
{
    char ns1 = 'c';
    //char igm;
    //char igg;
    printf("Digite o resultado do teste NS1: ");
    scanf("%c", &ns1);

    printf("%c\n", ns1);

    if (ns1 == 'c')
    {
        printf("Provavel infeccao previa.\n");
    }
    
}

int main()
{
    int tempo;
    printf("Digite o tempo de doença: ");
    scanf("%d", &tempo);
    if (tempo <= 6)
    {
        teste_rapido();
    } 
    

    return 0;
}