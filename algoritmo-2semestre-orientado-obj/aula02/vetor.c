#include <stdio.h>
#include <stdlib.h>
// ERROR
int mult(int *v, int n, int m, int i){
    if (i == 0)
    {
        return v[i] * m;
    }
}

int main()
{
    int *v;
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    v = (int*)malloc(sizeof(int)*n);
    if (v == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Digite: ");
        scanf("%d", &v[i]);
    }

    int j = 0;
    v = mult(v, n, m, j);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }
    free(v);
    return 0;
}
