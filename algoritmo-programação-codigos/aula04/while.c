#include <stdio.h>

int main()
{
    char resp = 's';
    int cont = 0;
    
    while (resp != 'n')
    {
        if (cont > 0)
        {
            printf("Repitindo...\n");
        }
        cont = cont + 1;
        scanf("%c", &resp);
    }
    return 0;
}