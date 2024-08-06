#include <stdio.h>

int main()
{
    int t1, t2;
    printf("Tamanho da matriz: ");
    scanf("%d %d", &t1, &t2);
    char matriz[t1][t2];

    int coeficiente;
    if (t1 == 3)
    {
        coeficiente = t1 - 2;
    } else if (t1 == 5)
    {
        coeficiente = t1 - 3;
    } else if (t1 == 7)
    {
        coeficiente = t1 - 4;
    } else 
        coeficiente = t1 - 5;
    
    for (int i = 0; i < t1; i++)
    {
        for (int j = 0; j < t2; j++)
        {
            if (i == coeficiente || j == coeficiente)
            {
                if (j != (t1-1))
                {
                    matriz[i][j] = 'x';
                    printf("%c|", matriz[i][j]);
                } else {
                    matriz[i][j] = 'x';
                    printf("%c", matriz[i][j]);
                }
            } else if (j != (t1-1))
            {
                printf(" |");
            }
            
        }
        printf("\n");
    }
    

    return 0;
}
