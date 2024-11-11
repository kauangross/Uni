#include <iostream>
using namespace std;

class Funcionario {
private:
    string Nome;
    double SalarioBase;

public:
    Funcionario(string n, double s):
        Nome(n), SalarioBase(s){}
    
    friend class FolhaPagamento;
};

class FolhaPagamento {
public:
    void pagamentoFinal(const Funcionario &funcionario){
        double pagamento;
        
        pagamento = funcionario.SalarioBase + 100 - 50;  

        cout << pagamento;
    }

};

int main()
{
    Funcionario funcionario("kauan", 1500);

    FolhaPagamento folha;

    folha.pagamentoFinal(funcionario);

    return 0;
}
