#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    FILE *arq;

    arq = fopen("arq_grav.txt", "wt"); // Cria um arquivo de texto para gravação
    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo.\n");
        return 1;
    }
    strcpy(str, "Linha de teste\nLinha de teste 2");
    int result = fputs(str, arq);
    if (result == EOF)
    {
        printf("Erro na gravação");
    }
    

    return 0;
}
