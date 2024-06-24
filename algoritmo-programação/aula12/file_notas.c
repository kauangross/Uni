#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, b, c;
    printf("Digite as 3 notas: ");
    scanf("%d %d %d", &a, &b, &c);

    FILE *f = fopen("notas.txt", "wt");
    if (f == NULL)
    {
        printf("Problemas na CRIACAO do arquivo.\n");
        return 1;
    }

    fprintf(f, "Nota: %d\nNota: %d\nNota: %d\n", a, b, c);
    if (a == EOF || b == EOF || c == EOF)
    {
        printf("Erro na gravação");
    }

    fclose(f);
    return 0;
}