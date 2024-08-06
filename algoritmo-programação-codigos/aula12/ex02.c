#include <stdio.h>
#include <string.h>

int main()
{
    char string[10];
    printf("Digite uma string: ");
    fgets(string, 10, stdin);
    int cont = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 10; j > 0; j--)
        {
            if (string[i] == string[j])
            {
                cont++;
            }
        }
    }
    int tam;
    tam = strlen(string);
    if (cont == tam)
    {
        printf("Sim");
    } else
        printf("Nao");
    return 0;
}
