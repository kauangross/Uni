#include <stdio.h>

int main()
{
    int nota[5];
    float media;
    float soma;
    for (int i = 0; i < 5; i++)
    {
        printf("Digite a nota: ");
        scanf("%d", &nota[i]);
        soma += nota[i];
    }
    media = soma / 5;
    printf("%.2f", media);
    return 0;
}
