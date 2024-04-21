#include <stdio.h>

int main() 
{
    int v = 7;
    
    for (int i = 0; i <= v; i++)
    {
        if (i == 0) // primeiro for = 1 ate v
        {
            for (int j = 1; j <= v; j++)
            {
                printf("%d", j);
            }
        } else if (i % 2 != 0) // for de quando o i é impar = decrescente
        {
            for (int j = (v-i); j >= 1; j--)
            {
                printf("%d", j);
            }
        } else if (i % 2 == 0) // for de quando o i é par = crescente
        {
            for (int j = 2; j <= (v-i); j++)
            {
                printf("%d", j);
            }
        } else {
            for (int j = 1; j <= (v-i); j++) // último for se o v for par
            {
                printf("%d", j);
            }
        } 
        printf("\n");
    }
    
    return 0;
}