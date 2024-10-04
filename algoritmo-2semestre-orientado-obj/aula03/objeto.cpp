#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Animal {
private:
    string tipo;
public:
    Animal(string tip): tipo(tip){} 

    virtual ~Animal(){}

    /*virtual void funcaobaseAnimal(){
        cout << "herda funcao base animal";
    }*/

    void testeAnimal(){}
};

class Pet {
private:
    string nome;

public:
    Pet(string nom): nome(nom){} 

    ~Pet(){}

    virtual void funcaobasePet(){
        cout << "herda funcao base pet";
    }
};

class Cachorro: public Animal, public Pet{
private:
    string raca;

public:
    Cachorro(string rac, string tip, string nom): raca(rac), Animal(tip), Pet(nom){} 

    ~Cachorro(){}

    /*void funcaobaseAnimal() override {
        cout << "funcao base animal reescrita" << endl;
    }

    void funcaobasePet() override {
        cout << "funcao base pet reescrita";
    }*/

    void testeCachorro(){}    
};

int main()
{
    Cachorro meudog("aaa", "b", "C");

    Animal *cachorro = new Cachorro("aa", "c", "d");

    Cachorro *dog = new Cachorro("aa", "b", "c");

    cachorro->testeAnimal();
    cachorro->testecachorro();

    //meudog.funcaobaseAnimal();
    //meudog.funcaobasePet();

    delete cachorro;
    delete dog;
    return 0;
}

// Criar um vetor de contabancarias
// Contas bancarias serias criadas atraves das derivadas
// Nao haveriam contas bancarias
// Criar tres vetores diferentes