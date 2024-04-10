#include <stdio.h>

int main()
{
    int n;
    printf("Numero de pilotos: ");
    scanf("%d", &n);
    int piloto_largada[n];
    int piloto_chegada[n];

    printf("\n");

    for (int i = 0; i < n; i++) // declarador do grid inicial
    {
        printf("Posicao %d do grid de largada: ", (i+1));
        scanf("%d", &piloto_largada[i]);
    }

    printf("\n");
    
    for (int i = 0; i < n; i++) // declarador do grid de chegada
    {
        printf("Posicao %d do grid de chegada: ", (i+1));
        scanf("%d", &piloto_chegada[i]);
    }
    
    printf("\n"); 

    int aux = 0;
    int ultrapassagens = 0;
    for (int i = 0; i < n; i++) // verificador de ultrapassagens
    {
        for (int j = (i + 1); j < n; j++)
        {
            if (piloto_largada[i] != piloto_chegada[i]) // Se o piloto da posição i do vetor for diferente da posição j do vetor, ele realoca, isso até o piloto estar na mesma posição, e quando acontece, contabiliza o num de ultrapassagem realizada
            {
                aux = piloto_largada[i];
                piloto_largada[i] = piloto_largada[j];
                piloto_largada[j] = aux;
                if (piloto_largada[i] == piloto_chegada[i]) // Se estiver no lugar certo, adiciona uma ultrapassagem
                {
                    ultrapassagens = ultrapassagens + (j - i); // ultrapassagem recebe j - i pois é a posição que ele estava, para a posição que ele foi, portanto, as posições do vetor que ele ultrapassou
                }
            }
        }   
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", piloto_largada[i]);
        printf("%d \n", piloto_chegada[i]);
    }

    printf("%d", ultrapassagens);

    return 0;
}