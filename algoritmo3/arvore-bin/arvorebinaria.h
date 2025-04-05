#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <iostream>
//#include <vector>
using namespace std;

class node {
public:
    int valor;
    node* esquerda;
    node* direita;
    int fatorB;

    node(int val);
};

class binarytree {
private:
    node* raiz;

    void adicionarNodoRecursivo(node*& atual, int val, bool& cresceu);
    //void inserirConjunto(vector<int>& valores);
    void removerRecursivo(int val, node*& atual, bool& diminuiu);
    void apagarNodo(node*& atual, bool& diminuiu);
    void apagararvore(node* temp);

    void rotacaoDireita(node*& pai);
    void rotacaoEsquerda(node*& pai);
    void rotacaoEsquerdaDireita(node*& pai);
    void rotacaoDireitaEsquerda(node*& pai);
    void realizarRotacao(node*& pai);

    void mostrarPreOrdem(node* atual);
    void mostrarEmOrdem(node* atual);
    void mostrarPosOrdem(node* atual);
    void mostrarIdentada(node* atual, int contador, bool esquerda);

    void BuscarNodo(node* atual, node*& aux, int valorBusca);
    node* AcharMaiorNodo(node* raiz_sub);
public:
    binarytree();
    ~binarytree();

    void menu();
    void UnidadeControle(int operacao);
};
#endif