#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.c"

int main()
{
    Produto *produtos;
    produtos = malloc(sizeof(Produto)* 9); // Vetor dinâmico do estoque com 9 produtos iniciais
    SetProdutos(produtos, 9); // Inicializa os produtos iniciais da loja
    int tamanho_loja = 9;
    int cod = 0;

    int chose; // variavel de escolha do usuario
    do
    {
        menu(); // Chama o menu


        
        scanf("%d", &chose);
    } while (chose <= 6 && chose > 0); // Repete até a resposta for maior que 6 ou menor que 0

    mostrar_estoque(produtos, tamanho_loja);

    return 0;
}