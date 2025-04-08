#include "arvorebinaria.h"
#include <iostream>
//#include <vector>

node::node(int val) : valor(val), esquerda(nullptr), direita(nullptr), fatorB(0) {}

binarytree::binarytree() : raiz(nullptr) {}
binarytree::~binarytree() {apagararvore(raiz);}

// Métodos básico
void binarytree::apagararvore(node* temp) {
    if (!temp) return;
    apagararvore(temp->esquerda);
    apagararvore(temp->direita);
    delete temp;
}

void binarytree::UnidadeControle(int operacao){
    int aux;
    switch (operacao){
        case 1: // Adicionar nodo
            {cout << "Digite o valor: ";
            cin >> aux;

            node* nodo_busca = nullptr;
            BuscarNodo(raiz, nodo_busca, aux);
            if(nodo_busca == nullptr){
                bool cresceu;
                adicionarNodoRecursivo(raiz, aux, cresceu);

                cout << "Nodo " << aux << " adicionado!" << endl << endl; 
                mostrarIdentada(raiz, 0, 0);
            }else
                cout << "Falha ao adicionar! Nodo existente." << endl;}
            break;
        case 2: // Reemover nodo
            {cout << "Digite o valor do nodo que deseja remover: " ;
            cin >> aux;
            
            node* nodo_busca = nullptr;
            BuscarNodo(raiz, nodo_busca, aux);
            if(raiz == nullptr){
                cout << "Arvore vazia!" << endl;
            } else if(nodo_busca != nullptr){
                    bool diminuiu;
                    removerRecursivo(aux, raiz, diminuiu);

                    cout << endl << "Nodo " << aux << " removido!" << endl << endl; 
                    mostrarIdentada(raiz, 0, 0);
            }else
                cout << endl << "Nodo nao econtrado!" << endl;}
            break;
        case 3: // Busca
            {node* nodo_busca = nullptr;
            cout << "Digite o valor: " << endl;
            cin >> aux;

            BuscarNodo(raiz, nodo_busca, aux);

            if(raiz == nullptr){
                cout << "Arvore vazia!" << endl;
            } else if(nodo_busca == nullptr){
                cout << "Nodo nao econtrado" << endl;
            }            }    
            break;
        case 4: // Exibir pre-ordem
            if(raiz != nullptr){mostrarPreOrdem(raiz);} else cout << "Arvore vazia!" << endl;
            break;
        case 5: // Exibir em-ordem
            if(raiz != nullptr){mostrarEmOrdem(raiz);} else cout << "Arvore vazia!" << endl;
            break;
        case 6: // Exibir pos-ordem
            if(raiz != nullptr){mostrarPosOrdem(raiz);} else cout << "Arvore vazia!" << endl;
            break;
        case 7: // Exibir arvore completa
            if(raiz != nullptr){mostrarIdentada(raiz, 0, 0);} else cout << "Arvore vazia!" << endl;
            break;
        default: // Finaliza
            cout << "Finalizando...";
            break;
    }
    cout << endl << endl;
}

void binarytree::adicionarNodoRecursivo(node*& atual, int val, bool& cresceu) {//Método percorre a função atrávez da recursão
    
    if(atual == NULL){ //Se no final da recursão chegar a null, então um novo nodo vai ser inserido
        atual = new node(val);
        cresceu = true; // Quando um novo nodo é inserido, a booleana vai ser true
        return;
    }
    //Se o valor for maior que o nodo atual, então ela vai para direita
    if (val > atual->valor) {
        adicionarNodoRecursivo(atual->direita, val, cresceu);
        if (cresceu) {
            atual->fatorB += 1; //Os antecedentes do novo nodo tem seu fator de balanceamento alterado
        }
    } else if(val < atual->valor) {
        adicionarNodoRecursivo(atual->esquerda, val, cresceu);
        if (cresceu) {
            atual->fatorB -= 1;
        }
    }
    realizarRotacao(atual);
    if(cresceu && atual->fatorB == 0){cresceu = false;}
}

void binarytree::removerRecursivo(int val, node*& atual, bool& diminuiu) {
    if(val < atual->valor) {//esquerda
        removerRecursivo(val, atual->esquerda, diminuiu);
        if(diminuiu){atual->fatorB+=1;}
    } else if (val > atual->valor) {//direita
        removerRecursivo(val, atual->direita, diminuiu);
        if(diminuiu){atual->fatorB-=1;}
    } else {
        apagarNodo(atual, diminuiu);
    }
    if(atual != NULL){
        realizarRotacao(atual);
        if(diminuiu && atual->fatorB != 0){diminuiu = false;}
    }
}

void binarytree::apagarNodo(node*& atual, bool& diminuiu){
    node* temp = atual;
    // Caso 1: Nó folha
    if (atual->esquerda == NULL) {
        atual = atual->direita;
        diminuiu = true;
        delete temp;
    }
    // Caso 2: Apenas um filho
    else if (atual->direita == NULL) {
        atual = atual->esquerda;
        diminuiu = true;
        delete temp;
    }
    // Caso 3: Dois filhos (remoção por cópia usando o maior modo da sub-árvore esquerda)
    else {
        temp = AcharMaiorNodo(temp->esquerda);
        atual->valor = temp->valor;
        removerRecursivo(temp->valor, atual->esquerda, diminuiu);
        if(diminuiu){atual->fatorB+=1;}
    }
}

node* binarytree::AcharMaiorNodo(node* raiz_sub) {
    while (raiz_sub->direita) {
        raiz_sub = raiz_sub->direita;
    }
    return raiz_sub;
}

void binarytree::BuscarNodo(node* atual, node*& nodo_busca, int valorBusca){ // Se não encontra, atual recebe null e mantém o aux como null, retornando o ptr nulo
    if (atual == nullptr || nodo_busca != nullptr) return; // Caso base: árvore vazia ou já encontrou

    if (atual->valor == valorBusca) {
        nodo_busca = atual;

        cout << "Nodo " << nodo_busca->valor << " encontrado:" << endl << endl;
        if (nodo_busca->esquerda != nullptr && nodo_busca->direita != nullptr) {
            cout << "->" << nodo_busca->valor << "<-" << endl << "   (E) " << nodo_busca->esquerda->valor << endl;
            cout << "   (D) " << nodo_busca->direita->valor << endl;
        } else if (nodo_busca->esquerda != nullptr) {
            cout << "->" << nodo_busca->valor << "<-" << endl << "   (E) " << nodo_busca->esquerda->valor << endl;
        } else if (nodo_busca->direita != nullptr) {
            cout << "->" << nodo_busca->valor << "<-" << endl << "   (D) " << nodo_busca->direita->valor << endl;
        } else if (nodo_busca == raiz) {
            cout << "Nodo eh uma raiz!" << endl;
        } else {
            cout << "Nodo eh uma folha!" << endl;
        }

        return;
    }

    // Busca recursiva nos filhos
    BuscarNodo(atual->esquerda, nodo_busca, valorBusca);
    BuscarNodo(atual->direita, nodo_busca, valorBusca);
}

// Balanceamento
void binarytree::rotacaoDireita(node*& pai){
    node* novoPai = pai->esquerda;
    pai->esquerda = novoPai->direita;
    novoPai->direita = pai;
    pai = novoPai;
}

void binarytree::rotacaoEsquerda(node*& pai){
    node* novoPai = pai->direita;
    pai->direita = novoPai->esquerda;
    novoPai->esquerda = pai;
    pai = novoPai;
}

void binarytree::rotacaoEsquerdaDireita(node*& pai){
    node* filho = pai->esquerda;
    rotacaoEsquerda(filho);
    pai->esquerda = filho;
    rotacaoDireita(pai);
}

void binarytree::rotacaoDireitaEsquerda(node*& pai){
    node* filho = pai->direita;
    rotacaoDireita(filho);
    pai->direita = filho;
    rotacaoEsquerda(pai);
}

void binarytree::realizarRotacao(node*& pai){
    node* filho;
    node* neto; //Caso precise de rotação dupla

    if(pai->fatorB == -2){//Rotaciona para a direita
        filho = pai->esquerda;
        if(filho->fatorB == -1){// Simples para a direita
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoDireita(pai);
        }
        else if(filho->fatorB == 0){ // Simples para a direita
            pai->fatorB = -1;
            filho->fatorB = 1;
            rotacaoDireita(pai);
        }
        else if(filho->fatorB == 1){// Rotaçao dupla
            neto = filho->direita;
            if(neto->fatorB == -1){
                pai->fatorB = 1;
                filho->fatorB = 0;
            }
            else if(neto->fatorB == 0){
                pai->fatorB = 0;
                filho->fatorB = 0;
            }
            else if(neto->fatorB == 1){
                pai->fatorB = 0;
                filho->fatorB = -1;
            }
            neto->fatorB = 0;
            rotacaoEsquerdaDireita(pai);
        }
    }
    else if(pai->fatorB == 2){//Rotaciona para a esquerda
        filho = pai->direita;
        if(filho->fatorB == 1){// Simples para a esquerda
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoEsquerda(pai);
        }
        else if(filho->fatorB == 0){ // Simples para a esquerda
            pai->fatorB = 1;
            filho->fatorB = -1;
            rotacaoEsquerda(pai);
        }
        else if(filho->fatorB == -1){// Rotaçao dupla
            neto = filho->esquerda;
            if(neto->fatorB == -1){
                pai->fatorB = 0;
                filho->fatorB = 1;
            }
            else if(neto->fatorB == 0){
                pai->fatorB = 0;
                filho->fatorB = 0;
            }
            else if(neto->fatorB == 1){
                pai->fatorB = -1;
                filho->fatorB = 0;
            }
            neto->fatorB = 0;
            rotacaoDireitaEsquerda(pai);
        }
    }
}

// Exibição
void binarytree::mostrarPreOrdem(node* atual){
    if(atual){
        cout << atual->valor << ", ";
        mostrarPreOrdem(atual->esquerda);
        mostrarPreOrdem(atual->direita);
    }
}

void binarytree::mostrarEmOrdem(node* atual) {
    if (atual != nullptr) {
        mostrarEmOrdem(atual->esquerda);
        cout << atual->valor << ", ";
        mostrarEmOrdem(atual->direita);
    }
}

void binarytree::mostrarPosOrdem(node* atual){
    if(atual){
        mostrarPosOrdem(atual->esquerda);
        mostrarPosOrdem(atual->direita);
        cout << atual->valor << ", ";
    }
}

void binarytree::mostrarIdentada(node* atual, int contador, bool esquerda){
    if(atual){
        for(int i = 0; i < contador; i++){//Utilizo a variável contador para medir a quantidade de espaços, deixando no terminal mais "indentado"
            cout << "  ";
        }
        if(contador > 0){//Raiz não possui necessidade de informar se é esquerda ou direita.
            if(esquerda == true){ //Se no parâmetro a booleana for verdadeira, então é o nodo da esquerda
                cout << "(E)";
            }
            else{ //Se é falsa, então é o nodo da direita
                cout << "(D)";
            }
        }
        cout << atual->valor << endl;
        contador += 1;

        mostrarIdentada(atual->esquerda, contador, true); //nodo da esquerda
        mostrarIdentada(atual->direita, contador, false); //nodo da direita
    }
}

void binarytree::menu(){
    cout << "======================================" << endl;
    cout << "|         MENU DA ARVORE AVL         |" << endl;
    cout << "======================================" << endl;
    cout << "| 1. Inserir elemento                |" << endl;
    cout << "| 2. Remover elemento                |" << endl;
    cout << "| 3. Buscar elemento                 |" << endl;
    cout << "| 4. Mostrar em pre-ordem (DFS)      |" << endl;
    cout << "| 5. Mostrar em ordem (DFS)          |" << endl;
    cout << "| 6. Mostrar em pos-ordem (DFS)      |" << endl;
    cout << "| 7. Mostrar arvore identada         |" << endl;
    cout << "| 0. Sair                            |" << endl;
    cout << "======================================" << endl;
    cout << "Digite a opcao desejada: ";
}