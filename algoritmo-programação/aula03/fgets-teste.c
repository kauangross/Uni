#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[50];
    char nome2[50];
    printf("Digite seu nome:\n", nome);
    scanf("%s", nome);
    printf("%s", nome);
    

    scanf("Digite seu nome %s\n", nome2);
    printf("%s", nome2);

    ffluch(stdin);
    return 0;
}
