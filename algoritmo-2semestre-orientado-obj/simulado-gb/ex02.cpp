#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


/* Adicionar produtos com as informações:
        •	Nome do produto
        •	Código do produto (número único)
        •	Preço
    
    Listar todos os produtos cadastrados.
    Buscar um produto pelo código e exibir suas informações.
    Atualizar o preço de um produto existente.
    Salvar e carregar os produtos de um arquivo chamado produtos.txt. */

void addProduto(fstream &arquivo){
    string nome;
    string cod;
    float preco;
    char sair = 'n';

    arquivo.open("../arquivo.txt", ios::app);
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo";
    }

    while (sair != 's'){
        cout << "Nome do produto: ";
        getline(cin, nome);
        fflush(stdin);
        cout << "Código: ";
        cin >> cod;
        fflush(stdin);
        cout << "Preco: ";
        cin >> preco;
        fflush(stdin);

        arquivo << "Produto: " << nome << endl;
        arquivo << "Codigo: " << cod << endl;
        arquivo << "Preco: " << preco << endl << endl;

        if(arquivo.fail()){
            cout << "erro";
        }

        cout << endl << "Deseja sair? [s][n]" << endl;
        cin >> sair;
    }

    arquivo.close();
}

void listarProdutos(fstream &arquivo){
    string linha;
    cout << endl << "Produtos:" << endl << endl;

    arquivo.open("../arquivo.txt", ios::in);
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    while(getline(arquivo, linha)){
        cout << linha << endl;
        if(linha.substr(0, 5) == "Preco"){
            cout << endl;
        }
    }
    arquivo.close();
}

void buscaProduto(fstream &arquivo){
    string linha;
    string nome;
    string codigo;
    string preco;
    string cod;

    cout << "Codigo";
    cin >> cod;

    arquivo.open("../arquivo.txt", ios::in);
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    while (getline(arquivo, linha)){
        if (linha.substr(0, 7) == "Produto"){
            nome = linha;
        }   

        getline(arquivo, linha);
         if (linha.substr(0, 6) == "Codigo"){
            codigo = linha.substr(8, linha.size());
        }   

        getline(arquivo, linha);
         if (linha.substr(0, 5) == "Preco"){
            preco = linha;
        }  

        if (cod == codigo){
            cout << endl << nome << endl << "Codigo: " + cod << endl << preco << endl; 
        }
    }

    arquivo.close();
}

    /*
         if (linha.substr(0, 6) == "Codigo"){
            int lineSize = linha.length();
            lineSize -= 7;
            string sub = linha.substr(7, lineSize);
        
            if (sub == cod){
                cout << "achou";
            }
           cout << linha.substr(8, lineSize) << cod << endl;
    */
    
void atualizarPreco(fstream &arquivo){
    string nome;
    string novoPreco;
    string linha;
    char sair = 'n';
    bool achou;

    arquivo.open("../arquivo.txt");
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo";
    }

    cout << "Nome do produto: ";
        getline(cin, nome);
        fflush(stdin);
        cout << "Novo preco: ";
        cin >> novoPreco;
        fflush(stdin);

    while(getline(arquivo, linha)){
        if (linha.substr(0, 7) == "Produto" && linha.substr(9, linha.length()-7) == nome){
            cout << linha.substr(0, 7);
            achou = 1;
        }
    }
    arquivo.close();

    arquivo.open("../arquivo.txt", ios::out);
    if (achou == 1){
        achou = 0;
        while(getline(arquivo, linha)){
            if (linha.substr(0, 7) == "Produto" && linha.substr(9, linha.length()-7) == nome){
                cout << linha.substr(0, 7);
                achou = 1;
            }

            if (achou == 1 && linha.substr(0, 7) == "Preco: "){
                cout << "achou";
                arquivo << "Preco: " + novoPreco;
                achou = 0;
            } else
                arquivo << linha;
        }
    }

    arquivo.close();
}

int main(){
    fstream arquivo;
    
    //addProduto(arquivo);

    //listarProdutos(arquivo);

    buscaProduto(arquivo);
    
    //atualizarPreco(arquivo);

    return 0;
}
