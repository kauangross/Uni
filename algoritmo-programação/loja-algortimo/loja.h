#ifndef LOJA_H
#define LOJA_H

//Structs:
typedef struct { // Struct do estoque
    int Codigo;
    char Descricao[30];
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
    char Descricao_Produto[30];
    int Codigo_Produto;
    int Quantidade_Produto;
    float Valor_Total;
} Compras;

//Protótipos:
void menu();

void CarrinhoDoCliente(Carrinho, int, Produto[], Compras[], int, int, double*, int);
void FinalizarCompra(Carrinho, Compras[], Produto[], int, int, double*, int);

void ReporEstoque(Produto[], int);

void mostrar_estoque(Produto[], int);

void mostrar_compras(Compras[], int);

void maior_compra(Compras[], int);

void SetProdutos(Produto[]); 

Produto CriarProduto(int, char[], int, float);

void limpa_tela();

#endif