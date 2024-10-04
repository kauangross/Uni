#include <iostream>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    float altura;

public:
    void setInfo(string name, int age, float high){
        nome = name;
        idade = age;
        altura = high;
    }

    void exibir(){
        cout << "Nome: " << nome << endl << "Idade: " << idade << endl << "Altura: " << altura << endl;
    }

};

int main()
{
    Pessoa eu;

    eu.setInfo("kauan", 18, 1.78);

    eu.exibir();

    return 0;
}
