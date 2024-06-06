#include <stdio.h>

#define MAX_ALUNOS 3
#define TAM_NOME 50

//declarar minha struct
typedef struct {
    char nome[TAM_NOME];
    int idade;
    float nota;
} Aluno;

void imprime(Aluno a){
    printf("Aluno: %s", a.nome);
}

int main()
{
    Aluno alunos[MAX_ALUNOS];

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("Digite o nome do aluno %d: ", i+1); // nome
        fgets(alunos[i].nome, TAM_NOME, stdin);

        printf("Digite a idade do aluno %d: ", i+1); // idade
        scanf("%d", &alunos[i].idade);

        printf("Digite a nota do aluno %d: ", i+1); // nota
        scanf("%f", &alunos[i].nota);

        while(getchar() !='\n');
    //    fflush(stdin);
    }

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("\nAluno %d\n", i+1);
        //printf("%s", alunos[i].nome);
        imprime(alunos[i]);

        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
        printf("\n");
    } 
    return 0;
}