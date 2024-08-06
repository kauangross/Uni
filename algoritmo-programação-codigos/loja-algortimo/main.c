#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.c"

// Grupo : Kauan Gross, Eduarda Maciel e Artur Costa

int main()
{
    int tamanho_loja = 10;
    Produto *produtos;
    produtos = malloc(sizeof(Produto)* tamanho_loja); // Vetor dinâmico do estoque com 10 produtos iniciais
    SetProdutos(produtos); // Inicializa os produtos iniciais da loja

    Compras *venda;
    venda = malloc(sizeof(Compras) * 20); // Vetor com máximo de 20 compras

    Carrinho carrinho; // Somente um, pois ele serve como auxiliar na hora da compra, somente

    int cod = 9; // auxiliares
    char desc[20];
    int quantidade;
    float valor;
    int chose;
    int n_compra = 0;
    double v_total = 0;
    do
    {
        menu(); // Chama o menu
        scanf("%d", &chose);
        int aux_cod_produto, aux_quantidade_produto = {0};
        switch (chose)
        {
        case 1: // Registrar venda
            fflush(stdin);
            system("clear"); // Limpa a tela

            printf("\n\n--Informe--\n");
            printf("Nome do cliente: ");
            fgets(carrinho.Cliente, 50, stdin);
            carrinho.Cliente[strcspn(carrinho.Cliente, "\n")] = '\0';
            do
            {
                printf("\n-------------Sessao de vendas-------------\n\n");
                printf("[0] para sair\nCodigo do produto: ");
                scanf("%d", &aux_cod_produto);
                if (aux_cod_produto == 0) // Se digitar zero finaliza
                {
                    printf("Compra finalizada.\n");
                    break;
                } else if (aux_cod_produto > cod || aux_cod_produto < 0) // se não existir código
                {
                    printf("\nCodigo de produto inexistente!\n");
                    limpa_tela();
                    break;
                } else {
                    printf("Quantidade desejada: ");
                    scanf("%d", &aux_quantidade_produto);

                    CarrinhoDoCliente(carrinho, cod, produtos, venda, aux_cod_produto, aux_quantidade_produto, &v_total, n_compra); // Função do carrinho
                    n_compra++; // Contador para informar a posição do vetor de compra
                } 
            } while (carrinho.Codigo_Produto != 0);
            system("clear"); //
            printf("Valor da venda: %.2lf\n", v_total);// Mostra o valor total da venda
            v_total = 0; // Zera o valor total pois finalizou a seção de venda
            limpa_tela();
            break;
        case 2: // Repor estoque
            system("clear");
            ReporEstoque(produtos, cod);
            limpa_tela();
            break;
        case 3: // Mostrar estoque
            system("clear");
            mostrar_estoque(produtos, cod);
            limpa_tela();
            break;
        case 4: // Mostrar compras
            system("clear");
            mostrar_compras(venda, n_compra);
            limpa_tela();
            break;
        case 5: // Maior compra
            system("clear");
            maior_compra(venda, n_compra);
            limpa_tela();
            break;
        case 6: // Adicionar mais produtos
            system("clear");
            fflush(stdin); // Limpa o buffer
            cod++; // Adiciona 1 ao código de listagem dos produtos para que o próximo adicionado seja o anterior + 1
            printf("\nDigite a descricao do produto: "); // Informações do novo produto
            fgets(desc, 20, stdin);
            desc[20] = '\0';
            printf("Digite a quantidade de estoque: ");
            scanf("%d", &quantidade);
            printf("Digite o PDV do produto: ");
            scanf("%f", &valor);
            if (cod > tamanho_loja) // se o tamanho da loja atingir seu limite, aumenta seu tamanho em 5 
            {
                tamanho_loja += 5;
                printf("%d", tamanho_loja);
                Produto *new_produtos; // Vetor aumentou o tamanho para caber mais produtos
                new_produtos = realloc(produtos, tamanho_loja * sizeof(Produto));
                if (new_produtos == NULL) // Teste de realocação
                {
                    printf("Erro na alocacao de memoria do array");
                    free(produtos);
                    return 1;
                }
    
                free(produtos);
                produtos = new_produtos; // Produtos recebe novo tamanho
                free(new_produtos); // Libera esse vetor
            }

            produtos[cod - 1] = CriarProduto(cod, desc, quantidade, valor); // Chama a função, adicionando os dados no vetor na posição do tamanho da loja - 1, que é a ultima posição
            limpa_tela();
            break;        
        default:
            printf("Saindo...");
            break;
        }
    } while (chose <= 6 && chose > 0); // Repete até a resposta for maior que 6 ou menor que 0
    return 0;
}