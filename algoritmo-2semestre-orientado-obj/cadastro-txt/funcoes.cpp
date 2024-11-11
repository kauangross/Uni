#include "funcoes.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Produto::Produto(string nome, int codigo, float preco)
    : Nome(nome), Codigo(codigo), Preco(preco) {}

Produto::~Produto(){}

void abrirEscrita() {
    string nome;
    int codigo;
    float preco;

    cout << "Digite o nome do produto: ";
    getline(cin, nome);
    cout << "Digite o preço do produto: ";
    cin >> preco;
    cout << "Digite o código do produto: ";
    cin >> codigo;

    Produto produto(nome, codigo, preco);

    ofstream dados;
    dados.open("produtos.txt", ios::app);

    if (!dados.is_open()) {
        cout << "Erro ao abrir o arquivo";
        return;
    }

    // Escreve os dados do produto no arquivo
    dados << "Nome: " << produto.Nome << endl;
    dados << "Código: " << produto.Codigo << endl;
    dados << "Preço: " << produto.Preco << endl << endl;

    dados.close();
    cout << "Dados salvos com sucesso!" << endl;
}

void abrirLeitura(){
    ifstream dados("produtos.txt");

    if (!dados.is_open()) {
        cout << "Erro ao abrir o arquivo";
        return;
    }

    string linha;
    while (getline(dados, linha))
    {
        cout << linha << endl;
    }
    dados.close();
}

void Buscar(){
    string nome_aux, nome;
    int achou = 1;
    cout << "Nome do produto: ";
    getline(cin, nome_aux);

    ifstream dados("produtos.txt");

    if (!dados.is_open()) {
        cout << "Erro ao abrir o arquivo";
        return;
    }

    nome = "Nome: " + nome_aux;

    string linha;
    while (getline(dados, linha))
    {
        if (nome == linha){
            cout << linha << endl;
            for (int i = 0; i < 3; ++i) {
                if (getline(dados, linha)) {
                    cout << linha << endl;
                }
            }
            achou = 0;
        } 
    }
    if (achou == 1){
        cout << "Produto nao encontrado";
    }
    dados.close();
}