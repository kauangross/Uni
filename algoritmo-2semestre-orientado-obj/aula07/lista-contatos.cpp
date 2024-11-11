#include <iostream>
using namespace std;
#include <string>
#include <list>

class Contato {
public:
    string Nome;
    int Numero;

    Contato(string no, int nu): 
        Nome(no), Numero(nu){}

    void display() const {
        cout << "Nome: " << Nome << endl << "Numero: " << Numero << endl << endl;
    } 
};

void Busca(const list<Contato>& contatos) {
    int aux = 1;
    for (const auto& contato : contatos) {
        if (contato.Nome == "kauan")
        {
            cout << "Contato encontrado!" << endl;
            contato.display();
            aux = 0;
            break;
        }
    }
    if(aux == 1)
        cout << "Contato nao encontrado!" << endl;
};

int main() {
    list<Contato> contatos;

    contatos.emplace_back("kauan", 997317533);
    contatos.emplace_back("Rosi", 997927424);
    contatos.emplace_front("First", 00000000);

    for (const auto& contato : contatos) {
        contato.display();
    }
    
    Busca(contatos);

    return 0;
}