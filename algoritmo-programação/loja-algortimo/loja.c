#include "loja.h"

//Funções:
void menu(){
    printf("\n         MENU            \n\n");
    printf("REGISTRAR VENDA          [1]\n");
    printf("REPOR ESTOQUE            [2]\n");
    printf("MOSTRAR ESTOQUE          [3]\n");
    printf("MOSTRAR COMPRAS          [4]\n");
    printf("MAIOR COMPRA             [5]\n");
    printf("ADICIONAR MAIS PRODUTOS  [6]\n");
    printf("SAIR...                  [7]\n\n");
}

void mostrar_estoque(Produto produtos[], int tamanho_loja){ // Mostra o estoque da loja
    for (int i = 0; i < tamanho_loja; i++) ///////////////////////////////////////////////////// CRIAR TABELA
    {
        printf("\nCodigo: %d\n", produtos[i].Codigo);
        printf("Descricao: %s\n", produtos[i].Descricao);
        printf("Estoque: %d\n", produtos[i].Estoque);
        printf("valor: %f\n", produtos[i].Valor);
        printf("\n");
    }
}

void SetProdutos(Produto produto[], int tam) // Inicializa os produtos
{
    produto[0] = CriarProduto(1, "Calca", 20, 112);
    produto[1] = CriarProduto(2, "Camisa", 18, 95);
    produto[2] = CriarProduto(3, "Bermuda", 23, 49.90);
    produto[3] = CriarProduto(4, "Saia", 12, 169);
    produto[4] = CriarProduto(5, "Blusa", 9, 120);
    produto[5] = CriarProduto(6, "Moletom", 4, 135);
    produto[6] = CriarProduto(7, "Meia", 17, 12.99);
    produto[7] = CriarProduto(8, "Tenis", 8, 183);
    produto[8] = CriarProduto(9, "Bota", 3, 219.90);
}


Produto CriarProduto(int codigo, char descricao[], int quantidade, float preco)
{ // Função para criar novos produtos, retornando um Produto
    Produto referencia;
    referencia.Codigo = codigo;
    strcpy(referencia.Descricao, descricao);
    referencia.Estoque = quantidade;
    referencia.Valor = preco;

    return referencia;
}