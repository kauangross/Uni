#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max = 0;
    int i = 0;
    while (i < 5)
    {
        i++;
        printf("%d", i);
        if (i > max)
        {
            max = i;
        }
    }
    printf("\nO maior valor da contagem eh: %d", max);
    return 0;
}