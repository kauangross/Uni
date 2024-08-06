#include <stdio.h>

void fatorial(int n)
{
    int fat = 1;
    for(int i = 1; i <= n; i++)
    {   
      fat = fat * i;
    }
    printf("Fatorial de %d: %d\n", n, fat);
}

int main()
{
    int num;
    printf("Digite o num que deseja saber o fatorial: ");
    scanf("%d", &num);

    fatorial(num);
    
    return 0;
}