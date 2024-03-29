#include <stdio.h>

int main()
{
    int linhas;

    scanf("%d", &linhas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 1; j <= ((i*2) + 1); j++)
        {
           printf("*"); 
        }
        printf("\n");   
    }
}