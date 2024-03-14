#include <stdio.h>
#include <math.h>

int main()
{
    printf("I++ e ++i\n");
    int i, j;
    i = 1;
    j = ++i;
    printf("%d %d\n", i, j);

    printf("\n");

    int i2, j2;
    i2 = 1;
    j2 = i2++;
    printf("%d %d\n", i2, j2);
    return 0;
}
