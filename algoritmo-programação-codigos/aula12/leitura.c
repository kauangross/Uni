#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[50];
    int idade;
    FILE *arq;
    arq = fopen("teste.txt", "r");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        return 1;
    }
    while (fscanf(arq, "%s %d", name, &idade) == 2)
    {
        printf("%s %d\n", name, idade);
    }
    fclose(arq);
    return 0;
}