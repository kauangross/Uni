#include <stdio.h> 
#include <string.h>
#define TAM_NOME 50
// Implementar uma função chamada criarAluno que recebe nome, idade e nota como
// parâmetros e retorna uma struct Aluno preenchida com esses valores.

typedef struct {
    char Nome[TAM_NOME];
    int Idade;
    float Nota;
} Aluno;

Aluno criarAluno(char nome[], int tam, int idade, int nota){
    Aluno N;
    N.Nome[tam] = nome[tam];
    N.Idade = idade;
    N.Nota = nota;
    return N;
}

int main()
{
    Aluno Kauan;
    char name[TAM_NOME];
    fgets(name, TAM_NOME, stdin);
    printf("Nome: %s\n", name);

    Kauan = criarAluno(name, TAM_NOME, 18, 10);
    printf("Nome: %s\n", Kauan.Nome);
    printf("Idade: %d\n", Kauan.Idade);
    printf("Nota: %.2f\n", Kauan.Nota);
    while(getchar() !='\n');
    return 0;
}