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

void mostrar_estoque(Produto produtos[], int codigo_final){ // Mostra o estoque da loja
    for (int i = 0; i < codigo_final; i++) ///////////////////////////////////////////////////// CRIAR TABELA
    {
        printf("\nCodigo: %d\n", produtos[i].Codigo);
        printf("Descricao: %s\n", produtos[i].Descricao);
        printf("Estoque: %d\n", produtos[i].Estoque);
        printf("valor: %.2f\n", produtos[i].Valor);
        printf("\n");
    }
}

void SetProdutos(Produto produto[]) // Inicializa os produtos
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

void ReporEstoque(Produto produtos[], int cod)
{
    int codigo, quantidade;
    int existente = 1; // auxiliar para informar se encontrou o código do produto
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    for (int i = 0; i < cod; i++)
    {
        if (codigo == produtos[i].Codigo)
        {
            printf("Digite a quantidade que deseja adicionar ao estoque: ");
            scanf("%d", &quantidade);
            produtos[i].Estoque += quantidade;
            existente = 0;
            break;
        }
    }
    if (existente == 1)
    {
        printf("Codigo de produto nao encontrado!\n");
    }
}

void CarrinhoDoCliente(Carrinho carrinho, int cod, Produto produto[], Compras venda[]){
    char finalizar;
    for (int i = 0; i < cod; i++)
    {
        if (carrinho.Codigo_Produto == produto[i].Codigo)
        {
            carrinho.Valor_Total = carrinho.Quantidade_Produto * produto[i].Valor;
            break;
        }
        printf("TEste de break");
    }
    printf("\n  SUMARIO\n");
    printf("Valor total: %f\n", carrinho.Valor_Total);
    printf("Quantidade: %d\n", carrinho.Quantidade_Produto);
    printf("\n\nDeseja finalizar a compra? [s] ou [n]\n");

    scanf("%c", &finalizar);

    if (finalizar == 's' || finalizar == 'S')
    {
        FinalizarCompra(carrinho, venda, produto);
    } else
        printf("finalizado\n");
}

void FinalizarCompra(Carrinho carrinho, Compras venda[], Produto produto[]){
       
}     