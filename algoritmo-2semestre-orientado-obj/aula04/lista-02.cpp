#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Elevador {
private:
    int AndarAtual;
    int TotalAndares; // Sem o térreo
    int Capacidade;
    int Pessoas;

public:
    Elevador(int n1, int andares, int capacidade, int n2):
        AndarAtual(n1), TotalAndares(andares), Capacidade(capacidade), Pessoas(n2)
    {}

    ~Elevador(){}

    void entra(){
        if (Pessoas < Capacidade)
        {
            Pessoas++;
            cout << "Entrou" << endl;
        } else
            cout << "Limite de pessoas atingido!" << endl;
    }

    void sai(){
        if (Pessoas > 0)
        {
            Pessoas--;    
            cout << "Saiu" << endl;
        } else
            cout << "Não tem ninguem" << endl;
    }

    void sobe(){
        if (AndarAtual != (TotalAndares-1))
        {
            AndarAtual++;
            cout << "Subiu" << endl;
        } else
            cout << "Ultimo andar!" << endl << "Andar atual: " << AndarAtual;
    }

    void desce(){
        if (AndarAtual != 0)
        {
            AndarAtual--;
            cout << "Desceu";
        } else
            cout << "Andar atual: Terreo";
    }

    int getAndar(){
        return AndarAtual;
    }

    int getTotalAndares(){
        return TotalAndares;
    }

    int getCapacidade(){
        return Capacidade;
    }

    int getPessoas(){
        return Pessoas;
    }
};


int main(){
    Elevador elevador(0, 4, 4, 0);

    elevador.entra();
    elevador.entra();

    elevador.sai();
    elevador.sai();
    elevador.sai();

    elevador.entra();

    elevador.sobe();

    elevador.sai();
    elevador.sai();

    elevador.sobe();
    elevador.sobe();
    elevador.sobe();
    elevador.sobe();

    elevador.desce();
    elevador.desce();
    elevador.desce();
    elevador.desce();
    return 0;
}