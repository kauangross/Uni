#include <stdio.h>
#include <string.h>

int main()
{
    char nome[30];
    fgets(nome, sizeof(nome), stdin);
    
    printf("%s", nome);
    return 0;
}