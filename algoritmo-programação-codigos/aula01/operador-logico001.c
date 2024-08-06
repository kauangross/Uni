#include <stdio.h>


int main()
{
    float na, nb;
    float media;
    printf("Digite a nota 1: ");
    scanf("%f", &na);
    printf("Digite a nota 2: ");
    scanf("%f", &nb);
    if ((na < 6) && (nb < 6))
    {
        printf("O aluno nao alcancou a media de primeira. \n");
    }
    media = ((na + nb)/2);
    printf("Sua nota final foi %2.1f. \n", media);
    if (media < 6)
    {
        printf("Considerando que a media geral eh 6, o aluno ficou com sua nota a baixo da expectativa!");
    }
    else 
    {
        printf("Aprovado.");
    }

    return 0;
}
