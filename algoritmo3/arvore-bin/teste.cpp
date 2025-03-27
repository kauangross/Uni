#include <iostream>
using namespace std;

class node{
public:
    int valor;
    node* esquerda;
    node* direita;

    node(int val): valor(val), esquerda(nullptr), direita(nullptr){}
};

class binarythree{
private:
    node* raiz; 

public:
    binarythree(): raiz(nullptr){}

    void addnode(int val){
        /*node* newnode = new node(val); 

        if(!raiz){ // Se nao tiver raiz, o novo nodo vira a raiz
            raiz = newnode;
            return;
        }

        node* temp = raiz; */
        int i1 = 1;
        int i2 = 0;
        while (i2 < 10){
            if (i2 > i1) { // Se o nodo for maior
                cout << ": " << i2;

            }
            else if (newnode->valor < temp->valor) { // Se o nodo for maior
                if (temp->esquerda == nullptr) {  // E a raiz não tiver filho à direita
                    temp->esquerda = newnode; // Vira filho
                    break;  // Sai do laço, pois o nó foi inserido
                }
                temp = temp->esquerda; // Se tiver filho à esquerda, temp agora aponta ao filho
            }    
        }
        i++;
    };

    void percorer(){}

    void apagarnodo(node* temp, node* temp_pai, int valor){
       
        if(valor == temp->valor){
            if (temp->esquerda != nullptr && temp->esquerda != nullptr){ // Se tiver doi filhos
                
            } else if (temp->esquerda == nullptr && temp->esquerda == nullptr){ // Se não tiver nenhum filho - simplesmente apaga
                delete temp;
            } else if(temp->esquerda != nullptr && temp->esquerda == nullptr) { // Se tiver apenas um na esquerda
                temp_pai = temp->esquerda;  // // O pai do nodo apagado vira pai do filho do nodo apagado
                delete temp;
            } else { // Se tiver apenas um na direita 
                temp_pai = temp->direita; // O pai do nodo apagado vira pai do filho do nodo apagado
                delete temp;
            }
            
            return;
        } // Se não houver mais folhas

        if(temp->esquerda){apagarnodo(temp->esquerda, temp, valor);} // Se tiver nodo à esquerda, passa o da esquerda;
        if(temp->direita){apagarnodo(temp->direita, temp, valor);} // Se tiver nodo à direita, passa o da direita, até achar o nodo que não possui filhos, então deleta eles na condição inicial da função
        
        return;
    }

    void apagararvore(node* temp){ // Recursão - recebe a raiz ao chamar a funcao delete
        if(temp->esquerda == nullptr && temp->direita == nullptr){delete temp; return;} // Se não houver mais folhas

        if(temp->esquerda){apagararvore(temp->esquerda);} // Se tiver nodo à esquerda, passa o da esquerda;
        if(temp->direita){apagararvore(temp->direita);} // Se tiver nodo à direita, passa o da direita, até achar o nodo que não possui filhos, então deleta eles na condição inicial da função

        delete temp; // Deleta sempre a raiz da sub-árvore
    }
    
    ~binarythree(){
        apagararvore(raiz);
    }
};


int main(){

    return 0;
}