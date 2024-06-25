#ifndef LOJA_H
#define LOJA_H

//Structs:
typedef struct { // Struct do estoque
    int Codigo;
    char Descricao[20];
    int Estoque;
    float Valor;
} Produto;

//Protótipos:
void menu();

void mostrar_estoque(Produto[], int);

void SetProdutos(Produto[]);

Produto CriarProduto(int, char[], int, float); // Declaração do protótipo da função com os tipos de variáveis



#endif