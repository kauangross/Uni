#include <iostream>
using namespace std;

class ContaBancaria{
private:
    float saldo;
public:
    ContaBancaria(float s):
        saldo(s){}

    ContaBancaria& depositar(float valor){
        this->saldo += valor;
        return *this;
    };

    ContaBancaria& remover(float valor){
        this->saldo -= valor;
        return *this;
    }

    void exibir(){
        cout << this->saldo;
    }
};


int main(){
    ContaBancaria conta(200);

    conta.depositar(100).remover(100);

    conta.exibir();

    return 0;
}