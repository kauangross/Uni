#include <stdio.h>

void fatorial(float n)
{
    printf("%f\n", n);
    int i = 1;
    while (i < n)
    {
        n *= (n - i);
        i++;
    }
    
    printf("%f", n);
}

int main()
{
    float num;
    printf("Digite o num que deseja saber o fatorial: ");
    scanf("%f", &num);

    fatorial(num);

    return 0;
}