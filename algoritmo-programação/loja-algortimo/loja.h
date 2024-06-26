#ifndef LOJA_H
#define LOJA_H

//Structs:
typedef struct { // Struct do estoque
    int Codigo;
    char Descricao[20];
    int Estoque;
    float Valor;
} Produto;

typedef struct{
    char Cliente[50];
    int Codigo_Produto[10]; // Maximo de 10 códigos, 10 produtos
    int Quantidade_Produto[10]; // Quantidade de cada produto (10 produtos) 
    float Valor_Total; 
} Carrinho;

typedef struct {
    char Cliente[50];
    int Codigo_Produto[10];
    int Quantidade_Produto[10];
    float Valor_Total;
} Compras;

//Protótipos:
void menu();

void mostrar_estoque(Produto[], int);

void SetProdutos(Produto[]);

Produto CriarProduto(int, char[], int, float); // Declaração do protótipo da função com os tipos de variáveis

void ReporEstoque(Produto[], int);

void CarrinhoDoCliente(Carrinho, int, Produto[], Compras[]);

void FinalizarCompra(Carrinho, Compras[], Produto[]);

#endif