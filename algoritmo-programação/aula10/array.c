#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;

    v = (int*)malloc(sizeof(int)*5);

    for (int i = 0; i < 5; i++)
    {
        v[i] = i+1;    
    }

    for (int i = 0; i < 5; i++)
    {
        printf("v[%d]: %d\n", i, v[i]);
    }
    free(v);
    return 0;
}