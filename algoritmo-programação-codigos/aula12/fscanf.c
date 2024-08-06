#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f = fopen("arquivo_teste.txt", "r");
    int i;
    while (fscanf(f, "%d", &i) == 1)
    {
        printf("%d\n", i);
    }
    fclose(f);
    return 0;
}
