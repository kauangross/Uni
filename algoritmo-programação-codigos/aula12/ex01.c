#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string_1[100];
    char string_2[100];

    fgets(string_1, 20, stdin);
    fgets(string_2, 20, stdin);

    if (strcmp(string_1, string_2) == 0)
    {
        printf("Sao strings iguais");
    } else {
        printf("Nao sao iguais");
    }

    char concatenado[200];

    strcpy(concatenado, string_1);
    strcat(concatenado, string_2);
    printf("\n%s\n", concatenado);

    char l;
    int cont = 0;
    printf("\nDigite uma letra: ");
    scanf("%c", &l);
    for (int i = 0; i < (strlen(concatenado)); i++)
    {
        if (concatenado[i] == l)
        {
            cont++;
        }
    }
    printf("\nVezes: %d\n", cont);
    printf("Tamanho: %d", strlen(concatenado));
    return 0;
}