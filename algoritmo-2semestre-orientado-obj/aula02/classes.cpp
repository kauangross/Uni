#include <iostream>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    float altura;

public:
    void setDados(string name, int idad, float altur){
        nome = name;
        idade = idad;
        altura = altur;
    }

    void mostrar(){
        cout << "Nome: " << nome << endl;
        cout << "idad: " << idade << endl;
        cout << "altura: " << altura << endl;
    }
};

int main()
{
    Pessoa pessoa;

    pessoa.setDados("kauan", 18, 1.78);
    
    pessoa.mostrar();

    return 0;
}
