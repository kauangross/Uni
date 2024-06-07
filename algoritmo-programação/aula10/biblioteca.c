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
    count = -1;
    countU = -1;
    int selectU, selectL = {0};

    while (chose != 6)
    {
        menu();
        printf("\nO que deseja?\n");
        scanf("%d", &chose);
        
        switch (chose)
        {
        case 1: // cadastrar livro
            system("cls");
            if (count <= TAM_BIBLIOTECA)
            {
                count++;
                for (int i = 0; i < TAM_BIBLIOTECA; i++)
                {
                    if (i == count)
                    {
                        LIVRO[i] = cadastrar_livros();
                        system("cls"); // limpa a tela
                        printf("\nSumario:\n");
                        printf("Nome do livro: %sAutor do livro: %sQuantidade: %d obras", LIVRO[i].Titulo, LIVRO[i].Autor, LIVRO[i].Quant);
                    }
                }
            } else {
                printf("Biblioteca atingiu o numero maximo de livros\n");
            }
            printf("\n");
            printf("\nAperte enter\n");
            getch(); // espera o usuario clicar para continuar
            system("cls"); // limpa a tela
            break;
        case 2: // cadastrar usuario
            system("cls");
            if (count <= TAM_USUARIOS)
            {
                countU++;
                for (int i = 0; i < TAM_USUARIOS; i++)
                {
                    if (i == countU)
                    {
                        USUARIO[i] = cadastrar_Usuario();
                        system("cls");
                        printf("\nSumario: ");
                        printf("\nNome: %sID: %d\n", USUARIO[i].Nome, USUARIO[i].Id);
                    }
                }
            } else {
                printf("\nQuantidade maxima de usuarios no sistema atingida!\n");
            }
            printf("\nAperte enter\n");
            getch(); // espera o usuario clicar para continuar
            system("cls"); // limpa a tela
            break;
        case 3: // pegar livro
            system("cls");
            printf("Selecione o usuario\n");
            if (countU >= 0 && countU >= 0)
            {
                for (int i = 0; i <= countU; i++)
                {
                    printf("[%d] Nome: %s", i + 1, USUARIO[i].Nome);
                    printf("     Id: %d\n", USUARIO[i].Id);
                    printf("\n");
                }
                scanf("%d", &selectU);
                printf("Selecione o livro\n");
                for (int i = 0; i < count; i++)
                {
                    printf("[%d] %s", i + 1, LIVRO[i].Titulo);
                    printf("Autor: %s", LIVRO[i].Autor);
                    printf("%d em estoque\n", LIVRO[i].Quant);
                    printf("\n");
                }
                scanf("%d", &selectL);
                system("cls");
                printf("Livro registrado na lista de livros do usuario!\n");
                LIVRO[(selectL - 1)].Quant--;
                printf("\nAperte enter\n");
                getch();       // espera o usuario clicar para continuar
                system("cls"); // limpa a tela
            } else
                printf("Nao existem usuarios cadastrados\n");
            break;
        //case 4: // devolver livro
        //    break;
        case 5: // informações de sistema
            system("cls"); // limpa a tela
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