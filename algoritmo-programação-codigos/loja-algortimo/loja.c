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

void CarrinhoDoCliente(Carrinho carrinho, int cod, Produto produto[], Compras venda[], int aux_cod_produto, int aux_quantidade_produto, double *v_total, int n_compra){
    char finalizar;
    int posicao = 0;
    int aux_i_produto;
    for (int i = 0; i < cod; i++)
    {   
        if (aux_cod_produto == produto[i].Codigo) // Acha qual o produto
        {
            aux_i_produto = i; // Pega a posição de vetor do produto
            carrinho.Codigo_Produto[posicao] = produto[i].Codigo; // Adiciona as informações ao carrinho
            carrinho.Quantidade_Produto[posicao] = aux_quantidade_produto; 
            carrinho.Valor_Total = carrinho.Quantidade_Produto[posicao] * produto[i].Valor;
            posicao++;

            printf("\n  SUMARIO\n");
            printf("Produto: %s\n", produto[i].Descricao);
            printf("Quantidade: %d\n", aux_quantidade_produto);
            printf("Valor total: %.2f\n", carrinho.Valor_Total);
            break;
        }
    }
    
    if (produto[aux_i_produto].Estoque < carrinho.Quantidade_Produto[posicao-1]){
        printf("\nQuantidade em estoque insuficiente!\n");
        printf("\nCompra cancelada!\n\n");
        posicao--; // Se não confirmar a compra, retorna a posição e sobrescreve os dados do carrinho na posição do vetor que estava
    } else if (produto[aux_i_produto].Estoque >= carrinho.Quantidade_Produto[posicao-1]){
        printf("\n\nDeseja finalizar a compra? [s] ou [n]\n");
        fflush(stdin);
        scanf("%c", &finalizar);
    }

    if (finalizar == 's' || finalizar == 'S') // Se desejar finalizar, chama a função que add o carrinho as compras
    {
        FinalizarCompra(carrinho, venda, produto, posicao, aux_i_produto, *&v_total, n_compra); // função para adicionar o carrinho as compras
    } 
}

void FinalizarCompra(Carrinho carrinho, Compras venda[], Produto produto[], int posicao, int aux_i_produto, double *v_total, int n_compra){
        strcpy(venda[n_compra].Cliente, carrinho.Cliente); // Adiciona as informações em um vetor de 20 posições
        strcpy(venda[n_compra].Descricao_Produto, produto[aux_i_produto].Descricao);
        venda[n_compra].Codigo_Produto = carrinho.Codigo_Produto[posicao-1];
        venda[n_compra].Quantidade_Produto = carrinho.Quantidade_Produto[posicao-1];
        venda[n_compra].Valor_Total = carrinho.Valor_Total;

        produto[aux_i_produto].Estoque -= venda[n_compra].Quantidade_Produto; // Baixa no estoque
        
        // Limpa a tela
        system("clear");

        printf("\nVenda efetuada!\n");
        printf("Cliente: %s\n", venda[n_compra].Cliente);
        printf("Produto: %s\n", venda[n_compra].Descricao_Produto);
        printf("Quantidade %d\n", venda[n_compra].Quantidade_Produto);  
        printf("Codigo: %d\n", venda[n_compra].Codigo_Produto);
        printf("Valor total: %.2f\n\n\n", venda[n_compra].Valor_Total);

        *v_total += venda[n_compra].Valor_Total; // Valor total informado ao finalizar a seção de compras, é um double passado como ponteiro
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
            system("clear");
            printf("\nReposicao de %s adicionado ao estoque\nQuantidade: %d\n", produtos[i].Descricao, quantidade);
            existente = 0;
            break;
        }
    }
    if (existente == 1)
    {
        printf("Codigo de produto nao encontrado!\n");
    }
}

void mostrar_estoque(Produto produtos[], int codigo_final){ // Mostra o estoque da loja
    for (int i = 0; i < codigo_final; i++) ///////////////////////////////////////////////////// CRIAR TABELA
    {
        printf("\nCodigo: %d\n", produtos[i].Codigo);
        printf("Descricao: %s\n", produtos[i].Descricao);
        printf("Estoque: %d\n", produtos[i].Estoque);
        printf("valor: %.2f\n\n", produtos[i].Valor);
    }
}

void mostrar_compras(Compras venda[], int posicao){
    if (posicao > 0)
    {
        for (int i = 0; i < posicao; i++)
        {
            printf("Cliente: %s\n", venda[i].Cliente);
            printf("Produto: %s\n", venda[i].Descricao_Produto);
            printf("Quantidade %d\n", venda[i].Quantidade_Produto);  
            printf("Codigo: %d\n", venda[i].Codigo_Produto);
            printf("Valor total: %.2f\n\n\n", venda[i].Valor_Total);
        }   
    } else {
        printf("\nNenhuma compra registrada!\n");
    }
}

void maior_compra(Compras venda[], int posicao){
    int maior_venda = 0;
    float valor = 0;

    if (posicao > 0)
    {
        for (int i = 0; i < posicao; i++)
        {
            for (int j = i+1; j <= posicao; j++)
            {
                if (venda[i].Valor_Total > venda[j].Valor_Total)
                {
                    if (venda[i].Valor_Total > valor)
                    {
                        valor = venda[i].Valor_Total;
                        maior_venda = i;
                    }
                } 
            }  
        }
        printf("\n\nMaior venda\n");
        printf("Cliente: %s\n", venda[maior_venda].Cliente);
        printf("Produto: %s\n", venda[maior_venda].Descricao_Produto);
        printf("Quantidade %d\n", venda[maior_venda].Quantidade_Produto);  
        printf("Codigo: %d\n", venda[maior_venda].Codigo_Produto);
        printf("Valor total: %.2f\n\n\n", venda[maior_venda].Valor_Total);
    } else {
        printf("\nNenhuma compra registrada!\n");
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

void limpa_tela(){
    printf("\nPressione qualquer botao para continuar.");
    getch(); // Espera o usuário pressionar
    system("clear"); // Limpa a tela
}