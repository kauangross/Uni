#include <iostream>
using namespace std;

class Funcionario {
private:
    string nome;
    int idade;
    float salario;

public:
    Funcionario(string n, int i, float s) : nome(n), idade(i), salario(s){
        cout << "Funcionario criado" << endl;
    } 

    virtual ~Funcionario(){
    }

    virtual void exibirInfo() const{
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Salario: " << salario << endl;
    }
};

class Gerente : public Funcionario {
private:
    string departamento;

public: 
    Gerente(string n, int i, float s, string dep) : Funcionario(n, i, s), departamento(dep){
        cout << "Gerente criado" << endl;
    }

    virtual ~Gerente(){
    }

    void exibirInfo() const override{
        Funcionario::exibirInfo();
        cout << "Departamento: " << departamento << endl;
    }
};


int main()
{
    // Cria funcionario dinamicamente
    Funcionario* funcionario_ex = new Funcionario("Nome Funcionario", 30, 1200);
    
    // Exibe informações
    funcionario_ex->exibirInfo();

    cout << endl;

    // Cria funcionario dinamicamente
    Gerente* gerente_ex = new Gerente("Nome Gerente", 35, 2000, "Marketing");

    // Exibe informações
    gerente_ex->exibirInfo();

    // Deleta o ponteiro
    delete funcionario_ex;
    delete gerente_ex;
    return 0;
}