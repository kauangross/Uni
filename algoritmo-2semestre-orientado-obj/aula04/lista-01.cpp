#include <iostream>
using namespace std;
#include <string>

class Pessoa {
private:
    string Nome;
    int Idade;
    int Altura;
public:
    Pessoa(string nome, int idade, int altura): 
        Nome(nome), Idade(idade), Altura(altura){}
    
    ~Pessoa(){}

    void exibir(){
        cout << Nome << " " << Idade << " " << Altura;
    }
};

int main()
{
    Pessoa kauan("kauan", 19, 180);
    kauan.exibir();

    return 0;
}
