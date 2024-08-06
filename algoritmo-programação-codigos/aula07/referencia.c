#include <stdio.h>

void incrementa(int *a, int *b)
{
    (*a)++;
    (*b)++;
} 


int main()
{
    int x = 5;
    int y = 10;

    printf("Antes: x = %d, antes: y = %d\n", x, y);

    incrementa(&x, &y);

    printf("Depois: x = %d, depois: y = %d\n", x, y);

    return 0;
}
