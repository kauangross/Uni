#include <stdio.h>

int main()
{
    int linhas;
    int space;

    scanf("%d", &linhas);

    // For que define o número de linhas.
    for (int i = 0; i < linhas; i++)
    {
        // Space que declara o número de espaços de cada linha. Corresponde ao for de baixo.
        space = (linhas - (i+1));
        // For que declara os espços.
        for (int k = 0; k < space; k++)
        {   
            printf(" ");
        }

        /*
            For para printar os asteriscos, dependendo do número de
            linhas. Multiplica-se o i por dois e adiciona um asterisco a cada linha.
        */ 
        for (int j = 1; j <= ((i*2) + 1); j++)
        {
        printf("*"); 
        }
        printf("\n");
    }
}