#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.c"

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
    do
    {
        menu(); // Chama o menu
        scanf("%d", &chose);

        switch (chose)
        {
        case 1: // Registrar venda
            printf("Nome do cliente: ");
            fgets(carrinho.Cliente, 50, stdin);
            do
            {
                printf("Codigo do produto: ");
                scanf("%d", &carrinho.Codigo_Produto);
                if (carrinho.Codigo_Produto == 0)
                {
                    printf("Compra finalizada ao digitar 0.\n");
                    break;
                }
                printf("Quantidade desejada: ");
                scanf("%d", &carrinho.Quantidade_Produto);

                CarrinhoDoCliente(carrinho, cod, produtos, venda);

                printf("\nValor total na main :%f\n", carrinho.Valor_Total);
            } while (carrinho.Codigo_Produto != 0);
            
            
            break;
        case 2: // Repor estoque
            ReporEstoque(produtos, cod);
            break;
        case 3: // Mostrar estoque
            mostrar_estoque(produtos, cod);
            break;
        case 4: // Mostrar compras

            break;
        case 5: // Maior compra

            break;
        case 6: // Adicionar mais produtos
            fflush(stdin); // Limpa o buffer

            cod++; // Adiciona 1 ao código de listagem dos produtos para que o próximo adicionado seja o anterior + 1

            printf("\nDigite a descricao do produto: "); // Informações do novo produto
            fgets(desc, 20, stdin);
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
            break;        
        default:
            break;
        }
    } while (chose <= 6 && chose > 0); // Repete até a resposta for maior que 6 ou menor que 0

    mostrar_estoque(produtos, tamanho_loja);
    return 0;
}