#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos
int lervetorDNA(char DNA[], int N, int limpa);
int lervetorPROTEINA(char proteina[], int N, int limpa);
void compara(char DNA[], int N, char proteina[], int M, int a, int b);

int main()
{
    int N, M;
    N = 10;
    M = 7;
    int q, a, b;
    /*
    printf("Tamanho da fita de DNA e tamanho da sua proteina: ");
    do
    {
        scanf("%d %d", &N, &M);
    } while ((M < 1) || (N < M) || (N > 100000)); // M tem que ser menor que o N
    */
    printf("%d %d\n", N, M);

    char DNA[N];
    char proteina[M];

    int limpa; // se receber 1, significa que o vetor deve ser reescrito;
    do { // Laço que le e verifica se foi digitado corretamente
        limpa = 0;
        limpa = lervetorDNA(DNA, N, limpa); // chama funçao e se retornar 1, deu errado e repete
    } while(limpa == 1);

    fflush(stdin); // limpa o buffer

    do { // Laço que le e verifica se foi digitado corretamente
        limpa = 0;
        limpa = lervetorPROTEINA(proteina, M, limpa);
    } while(limpa == 1);

    printf("\nDNA: %s\n", DNA);
    printf("Proteina: %s\n", proteina);


    fflush(stdin);
    printf("Digite o numero de verificacoes que deseja: ");
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        printf("Digite o inicio e fim: ");
        scanf("%d %d", &a, &b);
        verifica(DNA, N, proteina, M, a, b);
    }

    return 0;
}

int lervetorDNA(char DNA[], int N, int limpa){
    printf("Digite o DNA: ");
    fgets(DNA, N+1, stdin); // le o DNA
    printf("\nDNA: %s\n", DNA);
    for (int i = 0; i < N; i++)
    {
        if ((DNA[i] != 'A') && (DNA[i] != 'G') && (DNA[i] != 'C') && (DNA[i] != 'T'))
        {
            printf("\nErro na digitacao do DNA na posicao [%d].\n", i);
            printf("Pode ser quanto a forma do DNA ou quanto ao tamamho!\n");
            printf("Nucleotideos sao formados somente pelas bases adenina (A), guanina (G), citosina (C) e timina (T) e o tamanho deste DNA eh %d.\n", N+1);
            printf("Escreva novamente O DNA:\n");
            limpa = 1;
            fflush(stdin); // limpa o buffer
            break;
        }
    }
    return limpa;
}

int lervetorPROTEINA(char proteina[], int M, int limpa){
    printf("Digite a proteina: ");
    fgets(proteina, M+1, stdin); // le a proteina
    printf("\nProteina: %s\n", proteina);

    for (int i = 0; i < M; i++)
    {
        if ((proteina[i] != 'A') && (proteina[i] != 'G') && (proteina[i] != 'C') && (proteina[i] != 'T'))
        {
            printf("\nErro na digitacao da proteina na posicao [%d].\n", i);
            printf("Pode ser quanto a forma da proteina ou quanto ao tamamho!\n");
            printf("Nucleotideos sao formados somente pelas bases adenina (A), guanina (G), citosina (C) e timina (T) e o tamanho desta proteina eh %d.\n", M+1);
            printf("Escreva novamente a proteina:\n");
            limpa = 1;
            fflush(stdin); // limpa o buffer
            break;
        }
    }
    return limpa;
}

void verifica(char DNA[], int N, char proteina[], int M, int a, int b){
    int v = 0;
    char *array;
    char *ptr = 0;
    array = malloc(sizeof(char)*b);

    int i = 0; 
    while (a <= b) // copia a string pra outra variável
    {
        array[i] = proteina[(a-1)];

        i++;
        a++;
    }
    array[b] = '\0';
    
    printf("\n%s\n", array);
    fflush(stdin);
    char *DNA_2 = malloc(sizeof(char)*N);
    strcpy(DNA_2, DNA);
    fflush(stdin);
    i = 0;
    do
    {
        DNA_2 = strstr(DNA_2, array);
        if(DNA_2 != NULL)
        {
            v++;
            printf("\nAchou: %d\n", v);
        }
        i++;
        DNA_2++;
    } while(strstr(DNA_2, array));
    printf("\n%d\n", v);
}