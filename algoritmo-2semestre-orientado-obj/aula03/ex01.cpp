#include <iostream>
using namespace std;
#include <string>

class Veiculo {
protected:
    string motor;
    int capacidadeMotor;

public:
    Veiculo(string m, int capacidade) : motor(m), capacidadeMotor(capacidade){
    }

    virtual ~Veiculo(){}

    virtual void exibir() const{
        cout << "Motor: " << motor << endl << "Capacidade: " << capacidadeMotor << endl;
    }
};

class Carro : Veiculo {
protected:
    int portas;

public:
    Carro(string m, int capacidade, int porta) : Veiculo(m, capacidade), portas(porta){
    }

    ~Carro() override{}

    void exibir() const override{
        cout << "Motor: " << motor << endl << "Capacidade: " << capacidadeMotor << endl;
        cout << "N portas: " << portas;
   }
};

class Caminhao : Veiculo {
protected:
    int capacidadeCarga;

public:
    Caminhao(string m, int capacidade, int c) : Veiculo(m, capacidade), capacidadeCarga(c){
    }

    ~Caminhao() override {}

    void exibir() const override{
        cout << "Motor: " << motor << endl << "Capacidade: " << capacidadeMotor << endl;
        cout << "Capacidade: " << capacidadeCarga;
    }
};


int main()
{
    Carro carro("motor", 100, 4);
    Caminhao *caminhao = new Caminhao("motor", 100, 5000);

    carro.exibir();

    caminhao->exibir();

    //delete carro;
    delete caminhao;
    return 0;
}
