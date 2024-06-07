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

    printf("Digite o nome do usuario: ");
    fgets(usuario_referencia.Nome, TAM_CHAR, stdin);

    printf("Digite o ID [10 digitos]: ");
    scanf("%d", &usuario_referencia.Id);

    return usuario_referencia;
}

void menu();

int main()
{
    Livro LIVRO[TAM_BIBLIOTECA];
    Usuario USUARIO[TAM_USUARIOS];

    int chose, count, countU = 0;
    count = 0;
    countU = 0;
    int selectU, selectL = {0};

    while (chose != 6)
    {
        menu();
        printf("\nO que deseja?\n");
        scanf("%d", &chose);
        
        switch (chose)
        {
        case 1: // cadastrar livro
            if (count <= TAM_BIBLIOTECA)
            {
                for (int i = 0; i < TAM_BIBLIOTECA; i++)
                {
                    if (i == count)
                    {
                        LIVRO[i] = cadastrar_livros();
                        printf("\nNome do livro: %sAutor do livro: %sQuantidade: %d obras", LIVRO[i].Titulo, LIVRO[i].Autor, LIVRO[i].Quant);
                    }
                }
                printf("contador %d\n", count);
                count++;
            } else {
                printf("contador %d\n", count);
                printf("Biblioteca atingiu o numero maximo de livros\n");
            }
            break;
        case 2: // cadastrar usuario
            if (count <= TAM_USUARIOS)
            {
                for (int i = 0; i < TAM_USUARIOS; i++)
                {
                    if (i == countU)
                    {
                        USUARIO[i] = cadastrar_Usuario();
                        printf("\nNome: %s\nID: %d\n", USUARIO[i].Nome, USUARIO[i].Id);
                    }
                }
                countU++;
            } else {
                printf("\nQuantidade maxima de usuarios no sistema atingida!\n");
            }
            break;
        case 3: // pegar livro
            printf("Selecione o usuario\n");
            for (int i = 0; i <= countU; i++)
            {
                printf("[%d] Nome: %s", i+1, USUARIO[i].Nome);
                printf("     Id: %d\n", USUARIO[i].Id);
                printf("\n");
            }
            scanf("%d", &selectU);
            printf("Selecione o livro\n");
            for (int i = 0; i < count; i++)
            {
                printf("[%d] %s", i+1, LIVRO[i].Titulo);
                printf("Autor: %s", LIVRO[i].Autor);
                printf("%d em estoque\n", LIVRO[i].Quant);
                printf("\n");
            }
            scanf("%d", &selectL);
            LIVRO[(selectL-1)].Quant --; 
        case 4: // devolver livro

            break;
        case 5: // informações de sistema
            printf("Lista de livros\n");
            for (int i = 0; i < count; i++)
            {
                printf("%s", LIVRO[i].Titulo);
                printf("Autor: %s", LIVRO[i].Autor);
                printf("%d em estoque\n", LIVRO[i].Quant);
                printf("\n");
            }

            printf("Lista de usuarios no sistema\n");
            for (int i = 0; i <= countU; i++)
            {
                printf("[%d] Nome: %s", i+1, USUARIO[i].Nome);
                printf("     Id: %d\n", USUARIO[i].Id);
                printf("\n");
            }
            break;
        case 6:
            // exit(0);
            break;
        default:
            break;
        }
    }
    /*
    printf("\nImprimir Uuarios\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\nUsuario %d\n", i+1);
        printf("Nome: %s", USUARIO[i].Nome);
        printf("Id: %d\n", USUARIO[i].Id);
    }
    
    printf("\nImprimir biblioteca\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\nLivro %d\n", i+1);
        printf("Nome do livro: %s", LIVRO[i].Titulo);
        printf("Autor do livro: %s", LIVRO[i].Autor);
        printf("Quantidade: %d obras\n", LIVRO[i].Quant);
    }
    */
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