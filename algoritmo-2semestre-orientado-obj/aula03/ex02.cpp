#include <iostream>
#include <string>
using namespace std;

class Veiculo {
protected:
    string marca;
    string combustivel;

public:
    Veiculo(string m, string c) : marca(m), combustivel(c){
    }

    virtual ~Veiculo(){}

    void exibir(){
        cout << marca << endl << combustivel << endl;   
    }
};

class Eletronico {
protected:
    int tensao;
    int potencia;

public:
    Eletronico(int t, int p) : tensao(t), potencia(p){
    }
};

class CarroEletronico : public Veiculo, public Eletronico {
public:
    CarroEletronico(string m, string c, int t, int p) : Veiculo(m, c), Eletronico(t, p) {
    }  

    void exibirInfo_eletrico(){
        cout << marca << endl << combustivel << endl << tensao << endl << potencia << endl;   
    }
};


int main()
{
    CarroEletronico carro("peugeot", "diesel", 100, 200); 

    carro.exibir();
    return 0;
}
