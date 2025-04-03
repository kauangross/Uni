#include <iostream>
//#include "funcoes.cpp"
using namespace std;

class node {
public:
    int valor;
    node* esquerda;
    node* direita;

    node(int val) : valor(val), esquerda(nullptr), direita(nullptr) {}
};

class binarytree {
private:
    node* raiz;

public:
    binarytree() : raiz(nullptr) {}

    void addnode(int val) {
        node* newnode = new node(val);

        if (!raiz) { 
            raiz = newnode;
            return;
        }

        node* temp = raiz;
        while (temp != nullptr) {
            if (val > temp->valor) { 
                if (temp->direita == nullptr) {
                    temp->direita = newnode;
                    break;
                }
                temp = temp->direita;
            } else if (val < temp->valor) { 
                if (temp->esquerda == nullptr) {
                    temp->esquerda = newnode;
                    break;
                }
                temp = temp->esquerda;
            } else
                break;
        }
    }

    node* AcharMaiorNodo(node* raiz_sub) {
        while (raiz_sub->direita) {
            raiz_sub = raiz_sub->direita;
        }
        return raiz_sub;
    }

    node* apagarnodo(node* temp, int valor) {
        if (!temp) return temp;

        if (valor < temp->valor) {
            temp->esquerda = apagarnodo(temp->esquerda, valor);
        } else if (valor > temp->valor) {
            temp->direita = apagarnodo(temp->direita, valor);
        } else {
            // Caso 1: Nó folha
            if (!temp->esquerda && !temp->direita) {
                delete temp;
                return nullptr;
            }
            // Caso 2: Apenas um filho
            else if (!temp->esquerda) {
                node* temp_aux = temp->direita;
                delete temp;
                return temp_aux;
            } else if (!temp->direita) {
                node* temp_aux = temp->esquerda;
                delete temp;
                return temp_aux;
            }
            // Caso 3: Dois filhos (remoção por cópia usando o maior modo da sub-árvore esquerda)
            else {
                node* temp_aux = AcharMaiorNodo(temp->esquerda);
                temp->valor = temp_aux->valor;
                temp->esquerda = apagarnodo(temp->esquerda, temp_aux->valor);
            }
        }
        return temp;
    }

    void remover(int valor) {
        raiz = apagarnodo(raiz, valor);
    }

    void mostrarPreOrdem(node* atual){
        if(atual){
            cout << atual->valor << ", ";
            mostrarPreOrdem(atual->esquerda);
            mostrarPreOrdem(atual->direita);
        }
    }

    void mostrarEmOrdem(node* atual) {
        if (atual != nullptr) {
            mostrarEmOrdem(atual->esquerda);
            cout << atual->valor << ", ";
            mostrarEmOrdem(atual->direita);
        }
    }

    void mostrarPosOrdem(node* atual){
        if(atual){
            mostrarPosOrdem(atual->esquerda);
            mostrarPosOrdem(atual->direita);
            cout << atual->valor << ", ";
        }  
    }

    void percorrer() {
        mostrarPreOrdem(raiz);
        cout << endl;
        mostrarEmOrdem(raiz);
        cout << endl;
        mostrarPosOrdem(raiz);
        cout << endl;
    }

    void BuscarNodo(node* atual, node*& aux, int valorBusca){ // Se não encontra, atual recebe null e mantém o aux como null, retornando o ptr nulo
        if (aux){return;}
    
        if(atual && atual->valor != valorBusca){
            BuscarNodo(atual->esquerda, aux, valorBusca);
            BuscarNodo(atual->direita, aux, valorBusca);
        } else
            aux = atual;
    }

    void t(){
        //node* aux = BuscarNodo(raiz, 3);
        node* aux = nullptr;
        BuscarNodo(raiz, aux, 15);

        if(aux==nullptr){
            cout << "bret";
        }else
            cout << aux->valor;
    }

    void apagararvore(node* temp) {
        if (!temp) return;
        apagararvore(temp->esquerda);
        apagararvore(temp->direita);
        delete temp;
    }

    ~binarytree() {
        apagararvore(raiz);
    }

    /*int balanceamento(node* atual){
        if(atual){
            balanceamento(atual->esquerda, h);
            balanceamento(atual->direita, h);

            if(atual == raiz){return;};
            cout << "altura atual: "<< h << endl;
        }
    }*/

    void Altura(node* atual, int &h) {
        if (h == 0){h++;} // Desce um nível ao chamar a função, do nodo ao nodo filho

        if(atual->esquerda && atual->direita){
            h++;
            if(atual->esquerda){Altura(atual->esquerda, h);}
            if(atual->direita){Altura(atual->direita, h);}
        } else if(atual->esquerda){
            h++;
            Altura(atual->esquerda, h);
        } else if(atual->direita){
            h++;
            Altura(atual->direita, h);
        }        
    }

    void BuscaAltura(){
        int h = 0;
        Altura(raiz->esquerda, h);
        cout << h;
    }

    void mostrarIdentada(node* atual, int contador, bool esquerda){
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

    void mostrar(){
        mostrarIdentada(raiz, 0, 0);
    }
};

int main() {
    binarytree arvore;
    
    arvore.addnode(4);
    arvore.addnode(2);
    arvore.addnode(6);
    arvore.addnode(1);

    arvore.addnode(3);
    arvore.addnode(5);
    arvore.addnode(7);
    arvore.addnode(0);
    arvore.addnode(3);

    arvore.percorrer();

    //arvore.show();

    //arvore.BuscaAltura();

    //arvore.t();
    
    arvore.mostrar();

    arvore.remover(50);
    return 0;
}