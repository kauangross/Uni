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

    node* apagarnodo(node* atual, int valor) {
        if (!atual) return atual;

        if (valor < atual->valor) {
            atual->esquerda = apagarnodo(atual->esquerda, valor);
        } else if (valor > atual->valor) {
            atual->direita = apagarnodo(atual->direita, valor);
        } else {
            // Caso 1: Nó folha
            if (!atual->esquerda && !atual->direita) {
                delete atual;
                return nullptr;
            }
            // Caso 2: Apenas um filho
            else if (!atual->esquerda) {
                node* temp_aux = atual->direita;
                delete atual;
                return temp_aux;
            } else if (!atual->direita) {
                node* temp_aux = atual->esquerda;
                delete atual;
                return temp_aux;
            }
            // Caso 3: Dois filhos (remoção por cópia usando o maior modo da sub-árvore esquerda)
            else {
                node* temp_aux = AcharMaiorNodo(atual->esquerda);
                atual->valor = temp_aux->valor;
                atual->esquerda = apagarnodo(atual->esquerda, temp_aux->valor);
            }
        }
        return atual;
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

    void Busca(node* atual, node*& aux, int valorBusca){ // Aux retorna o ponteiro apontando para o nodo ou null
        if (aux){return;}
    
        if(atual && atual->valor != valorBusca){
            Busca(atual->esquerda, aux, valorBusca);
            Busca(atual->direita, aux, valorBusca);
        } else
            aux = atual;
    }

    void BuscarNodo(){
        //node* aux = BuscarNodo(raiz, 3);
        node* aux = nullptr;
        Busca(raiz, aux, 15);

        if(aux==nullptr){
            cout << "bret";
        }else
            cout << aux->valor;
    }

    void apagararvore(node* atual) {
        if (!atual) return;
        apagararvore(atual->esquerda);
        apagararvore(atual->direita);
        delete atual;
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

    /*void Altura(node* atual, int &h) {
        if (h == 0){h++;} // Desce um nível ao chamar a função, do nodo ao nodo filho

        

        if(atual->esquerda && atual->direita){
            int h_aux = 0;
            if(){
                if(atual->esquerda){Altura(atual->esquerda, h);}
            } else {
                if(atual->direita){Altura(atual->direita, h);}
            }
            h++;
        } else if(atual->esquerda){
            Altura(atual->esquerda, h);
            h++;
        } else if(atual->direita){
            Altura(atual->direita, h);
            h++;
        }        
    }*/

    int Altura(node* atual, int h) {
        if (atual == nullptr) {return h;} // Caso base: nó vazio retorna a altura acumulada
        if (h == 0) {h++;} // Desce um nível ao chamar a função, do nodo ao nodo filho
        
        if(atual->esquerda && atual->direita){        
            int hE = Altura(atual->esquerda, h + 1); // Altura subárvore da esquerda
            int hD = Altura(atual->direita, h + 1); // Altura subárvore da direita
            if(hE >= hD){
                h = hE;
            } else if(hE < hD){
                h = hD;
            }
        } else if(atual->esquerda){
            h = Altura(atual->esquerda, h + 1);
        } else if(atual->direita){
            h = Altura(atual->direita, h + 1);
        }
        return h;
    }


    void BuscaAltura(){
        int h = 0;
        h = Altura(raiz->esquerda, h);
        cout << "Altura subárvore esquerda: " << h << endl;
        h = 0;
        h = Altura(raiz->direita, h);
        cout << "Altura subárvore direita: " << h << endl;
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
    
    arvore.addnode(11);
    arvore.addnode(5);
    arvore.addnode(2);
    arvore.addnode(6);
    arvore.addnode(9);
    arvore.addnode(8);

    
    arvore.addnode(7);
    arvore.addnode(10);
    arvore.addnode(13);
    arvore.addnode(-1);
    arvore.addnode(-2);
    arvore.addnode(1);
    
   
    arvore.addnode(13);

    arvore.percorrer();

    //arvore.show();

    //arvore.BuscaAltura();

    //arvore.t();
    
    arvore.mostrar();

    arvore.BuscaAltura();

    arvore.remover(50);
    return 0;
}