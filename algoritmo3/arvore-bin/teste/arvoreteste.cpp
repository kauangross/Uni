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
        node* newnode = new node(val); 

        if(!raiz){ // Se nao tiver raiz, o novo nodo vira a raiz
            raiz = newnode;
            return;
        }

        node* temp = raiz;

        while (temp != nullptr){
            if (newnode->valor > temp->valor) { // Se o nodo for maior
                if (temp->direita == nullptr) { // E a raiz não tiver filho à direita
                    temp->direita = newnode; // Vira filho
                    break;  // Sai do laço, pois o nó foi inserido
                }
                temp = temp->direita; // Se tiver filho à direita, temp agora aponta ao filho
            }
            else if (newnode->valor < temp->valor) { // Se o nodo for maior
                if (temp->esquerda == nullptr) {  // E a raiz não tiver filho à direita
                    temp->esquerda = newnode; // Vira filho
                    break;  // Sai do laço, pois o nó foi inserido
                }
                temp = temp->esquerda; // Se tiver filho à esquerda, temp agora aponta ao filho
            }    
        }

    };

    void apagarnodo(node* temp, node* temp_pai, int valor){
        if(valor == temp->valor){
            if(!temp_pai && temp == raiz){ // Se for a raiz
                
                return;
            }

            if (temp->esquerda && temp->direita){ // Se tiver dois filhos
                node* temp_raiz = temp->esquerda;
                apagarnodo_doisfilhos(temp->esquerda, temp_raiz, valor); // Sub-árvore da esquerda para achar o maior nodo

                return;
            } else if (!temp->esquerda && !temp->direita){ // Se não tiver nenhum filho 
                if (temp_pai->esquerda == temp){ // Se for filho na esquerda, libera a memória do pai na esquerda
                    temp_pai->esquerda = nullptr;
                } else{ // Se for filho da direita, libera a memória do pai na direita
                    temp_pai->direita = nullptr;
                }    
                delete temp;
                return;
            } else if(temp->esquerda && !temp->direita) { // Se tiver apenas um filho na esquerda
                
                temp_pai->esquerda = temp->esquerda;  // // O pai do nodo apagado vira pai do filho do nodo apagado
                delete temp;
                
                return;
            } else { // Se tiver apenas um na direita 
                temp_pai->direita = temp->direita; // O pai do nodo apagado vira pai do filho do nodo apagado
                delete temp;
                return;
            }
            
            return;
        } // Se não houver mais folhas

        if(temp->esquerda){apagarnodo(temp->esquerda, temp, valor);} // Se tiver nodo à esquerda, passa o da esquerda;
        if(temp->direita){apagarnodo(temp->direita, temp, valor);} // Se tiver nodo à direita, passa o da direita, até achar o nodo que não possui filhos, então deleta eles na condição inicial da função
        return;
    }
//
    void apagarnodo_doisfilhos(node* temp, int valor){
        node* temp_aux = AcharMaiorNodo(temp_aux->esquerda, temp_aux->esquerda);
        
        temp = temp_aux;

    }

    Node* AcharMaiorNodo(Node* raiz_sub, node* sucessor;) {
        while (raiz_sub->left) {
            sucessor = raiz_sub;
            raiz_sub = raiz_sub->left;
        }
        return raiz_sub;
    }

    void mostrarEmOrdem(node* atual){
        if(raiz !- nullptr){return 0;
        } else{
            mostrarEmOrdem(atual->esquerda);
            cout << atual->valor;
        }
    }
//
    void apagarraiz(node* temp){
        
        if (temp != raiz){
            return;
        }

        if (temp->esquerda && temp->direita){ // Se tiver dois filhos precisa escolher um
                
            return;
        } else if (!temp->esquerda && !temp->direita){ // Se não tiver nenhum filho 
            delete temp;
            raiz = nullptr;
            return;
        } else if(temp->esquerda && !temp->direita) { // Se tiver apenas um filho na esquerda
            raiz = temp->esquerda;  // O filho da esquerda vira a raiz;
            delete temp;
            return;
        } else { // Se tiver apenas um na direita 
            raiz = temp->direita; // O pai do nodo apagado vira pai do filho do nodo apagado
            delete temp;
            return;
        }  
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