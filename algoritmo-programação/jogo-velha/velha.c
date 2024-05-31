#include <stdio.h>

void tabI(int vetor[3][3], int n, int m)
{
    int i = 0;
    while (i < 3)
    {   
        int j = 0;
        while (j < 3)
        {
            if (j == 0 || j == 1)
            {
                printf(" %d |", vetor[i][j]);
            } else if (j == 2)
            {
                printf("%d ", vetor[i][j]);
            } 
            j++;
        }
        printf("\n --|---|--\n");
        i++;
    }
}

void tab(int vetor[3][3], int n, int m, int jogada)
{
    int i = 0;
    while (i < 3)
    {   
        int j = 0;
        while (j < 3)
        {
            if (j == 0 || j == 1)
            {
                if (vetor[i][j] == 0)
                {
                   printf(" X |");
                } else if (vetor[i][j] == 10)
                {
                    printf(" O |");
                } else
                    printf(" %d |", vetor[i][j]);
            } else if (j == 2)
            {
                if (vetor[i][j] == 0)
                {
                   printf(" X ");
                } else if (vetor[i][j] == 10)
                {
                    printf(" O ");
                } else
                    printf(" %d ", vetor[i][j]);
                } 
            j++;
        }
        printf("\n --|---|--\n");
        i++;
    }
}

int vezX(int vetor[3][3], int n, int m, int aux, int jogada)
{
    int valido;
    do
    {
        valido = 0;
        printf("Vez do X: ");
        scanf("%d", &aux);
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (aux == vetor[i][j])
                {
                    vetor[i][j] = 0;
                    valido = 1;
                    break;
                }
            }
        }
    } while (valido == 0);
    jogada = 1;
    return jogada;
}

int vezO(int vetor[3][3], int n, int m, int aux, int jogada)
{
    int valido;
    do
    {
        valido = 0;
        printf("Vez do 0: ");
        scanf("%d", &aux);
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (aux == vetor[i][j])
                {
                    vetor[i][j] = 10;
                    valido = 1;
                    break;
                }
            }
        }
    } while (valido == 0);
    jogada = 0;
    return jogada;
}

int verificador(int vetor[3][3], int n, int m, int cont)
{
    printf("\nCont: %d\n", cont);
    
    if (vetor [0][0] == vetor [0][1] && vetor [0][1] == vetor[0][2])
    {   
        return 1;
    } else if (vetor [1][0] == vetor [1][1] && vetor [1][1] == vetor[1][2])
    {
        return 1;
    } else if (vetor [2][0] == vetor [2][1] && vetor [2][1] == vetor[2][2])
    {
        return 1;
    } else if (vetor [0][0] == vetor [1][0] && vetor [1][0] == vetor[2][0])
    {
        return 1;
    } else if (vetor [0][1] == vetor [1][1] && vetor [1][1] == vetor[2][1])
    {
        return 1;
    } else if (vetor [0][2] == vetor [1][2] && vetor [1][2] == vetor[2][2])
    {
        return 1;
    } else if (vetor [0][0] == vetor [1][1] && vetor [1][1] == vetor[2][2])
    {
        return 1;
    } else if (vetor [2][0] == vetor [1][1] && vetor [1][1] == vetor[0][2])
    {
        return 1;
    } else if (cont == 9)
    {
        return 1; 
    } else
        return 0;
}

int main()
{
    int vetor[3][3] = { 1, 2, 3,
                        4, 5, 6,
                        7, 8, 9 };
    int aux;
    int contador = 0;
    int jogada;
    int fim = 0;

    tabI(vetor, 3, 3);

    do
    {
        jogada = vezX(vetor, 3, 3, aux, jogada); // Vez de jogar do X
        tab(vetor, 3, 3, jogada); // Chama o tabuleiro
        contador++; // Adiciona mais um ao contador de jogadas (9 jogadas da velha)
        fim = verificador(vetor, 3, 3, contador); // Verifica se o x ganhou
        if (fim == 1) // Se fim retornar 1 da função, alguem ganhou ou deu velha e o jogoacaba
        {
            printf("X ganhou"); // Se entrar, x ganhou
            break;
        }

        jogada = vezO(vetor, 3, 3, aux, jogada); // Vez de jogar do O
        tab(vetor, 3, 3, jogada); // Chama o tabuleiro
        contador++; // Adiciona mais um ao contador de jogadas (9 jogadas da velha)
        fim = verificador(vetor, 3, 3, contador); // Verifica se o O ganhou
        if (fim == 1)
        {
            printf("O ganhou"); // Se entrar, O ganhou
            break;
        }
    } while(fim != 1);
    return 0;
}