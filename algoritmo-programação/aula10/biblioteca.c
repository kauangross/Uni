#include <stdio.h>
#define TAM_CHAR 50
#define TAM_BIBLIOTECA 10
#define TAM_USUARIOS 10

typedef struct
{
    char Titulo[TAM_CHAR];
    char Autor[TAM_CHAR];
    int Quant;
} Livro;

typedef struct
{
    char Nome[TAM_CHAR];
    int Id;
} Usuario;

Livro cadastrar_livros(){
    Livro livro_referencia;
    fflush(stdin);
    printf("Digite o titulo do livro: ");
    fgets(livro_referencia.Titulo, TAM_CHAR, stdin);

    printf("Digite o nome do autor do livro: ");
    fgets(livro_referencia.Autor, TAM_CHAR, stdin);

    printf("Digite a quantidade do livro: ");
    scanf("%d", &livro_referencia.Quant);
    return livro_referencia;
}

Usuario cadastrar_Usuario(){
    Usuario usuario_referencia;
    fflush(stdin);
    
    return usuario_referencia;
}

void menu();

int main()
{
    Livro LIVRO[TAM_BIBLIOTECA];
    Usuario PESSOAS[TAM_USUARIOS];

    int chose, countB, countU = 0;

    while (chose != 6)
    {
        menu();
        printf("\nO que deseja?\n");
        scanf("%d", &chose);
        
        switch (chose)
        {
        case 1: // cadastrar livro
            if (countB <= TAM_BIBLIOTECA)
            {
                for (int i = 0; i < TAM_BIBLIOTECA; i++)
                {
                    if (i == countB)
                    {
                        LIVRO[i] = cadastrar_livros();
                        printf("\nNome do livro: %sAutor do livro: %sQuantidade: %d obras", LIVRO[i].Titulo, LIVRO[i].Autor, LIVRO[i].Quant);
                    }
                }
                countB++;
            }
            else
                printf("Biblioteca atingiu o numero maximo de livros");
            break;
        case 2: // cadastrar usuario
            
            break;
        case 3: // pegar livro

            break;
        case 4: // devolver livro

            break;
        case 5: // informações de sistema

            break;
        case 6:
            // exit(0);
            break;
        default:
            break;
        }
    }

    printf("\nImprimir biblioteca\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\nLivro %d\n", i+1);
        printf("Nome do livro: %s", LIVRO[i].Titulo);
        printf("Autor do livro: %s", LIVRO[i].Autor);
        printf("Quantidade: %d obras\n", LIVRO[i].Quant);
    }

    while(getchar() !='\n');
    //printf("\nNome do livro: %sAutor do livro: %sQuantidade: %d obras", LIVRO[0].Titulo, LIVRO[0].Autor, LIVRO[0].Quant);
    return 0;
}

void menu(){
    printf("       BIBIOTLECA\n");
    printf("CADASTRAR LIVRO        [1]\n");
    printf("CADASTRAR USUARIO      [2]\n");
    printf("ALUGAR LIVRO           [3]\n");
    printf("DEVOLVER LIVRO         [4]\n");
    printf("INFORMACOES DE ESTOQUE [5]\n");
    printf("SAIR...                [6]");
}