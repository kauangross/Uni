#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Digite as dimensoes(x, y): ");
    scanf("%d %d", &x, &y);
    printf("A area corresponde: %d m^2", x*y);
    return 0;
}
