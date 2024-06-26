#include <stdio.h>

void declarador(int piloto[], int n)
{
    for (int i = 0; i < n; i++) // declarador do grid inicial
    {
        printf("Posicao %d: ", (i+1));
        scanf("%d", &piloto[i]);
    }
    printf("\n");
}

int verificador(int piloto_largada[], int piloto_chegada[], int n)
{
    int ultrapassagens = 0;
    int aux = 0;
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
    return ultrapassagens;
}

int main()
{
   int n; // Número de pilotos
    printf("Numero de pilotos: ");
    scanf("%d", &n);

    // Vetores dos pilotos
    int piloto_largada[n];
    int piloto_chegada[n];
    
    printf("\n");

    printf("Declare as posicoes INICIAIS do grid: \n");
    declarador(piloto_largada, n); // Chama a função para digitar o grid de largada
    printf("Declare as posicoes FINAIS do grid: \n");
    declarador(piloto_chegada, n); // Chama a função para digitar o grid de chegada

    printf("\n"); 

    int ultrapassagens = verificador(piloto_largada, piloto_chegada, n); // Chama a função que conta as ultrapassagens
    
    for (int i = 0; i < n; i++) // Digita os pilotos para verificar se o programa deu certo
    {
        printf("%d ", piloto_largada[i]);
        printf("%d \n", piloto_chegada[i]);
    }

    printf("%d ultrapassagens", ultrapassagens);
    return 0;
}