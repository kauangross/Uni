#include <stdio.h>

#define lin 3
#define col 3

int main()
{
    int matriz[lin][col];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int dp1, dp2, dp3;
    dp1 = matriz[0][0] * matriz[1][1] * matriz[2][2];
    dp2 = matriz[0][1] * matriz[1][2] * matriz[2][0];
    dp3 = matriz[0][2] * matriz[1][0] * matriz[2][1];

    int ds1, ds2, ds3;
    ds1 = -(matriz[0][2] * matriz[1][1] * matriz[2][0]);
    ds2 = -(matriz[0][0] * matriz[1][2] * matriz[2][1]);
    ds3 = -(matriz[0][1] * matriz[1][0] * matriz[2][2]);

    int result = dp1 + dp2 + dp3 + ds1 + ds2 + ds3;
    printf("%d\n", result);

    if (result != 0)
    {
        printf("A matriz eh INVERSIVEL;\n");
    } else
        printf("A matriz nao eh INVERSIVEL;\n");
    return 0;
}