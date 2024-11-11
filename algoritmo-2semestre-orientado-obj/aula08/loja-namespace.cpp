#include <iostream>
using namespace std;
#include <string>
#include <vector>

namespace Shopping {
      namespace Funcionarios {

        class Funcionario {
        private:
            string Nome;
            int Id;
            string Cargo;
        
        public:
            Funcionario(string nome,  int id, string cargo):
                Nome(nome), Id(id), Cargo(cargo){}

            void dispalayInfo(){
                cout << Nome << endl << Id << endl << Cargo << endl;
            }
        };

    };

    namespace Loja {

        class loja {
        private:
            vector<Shopping::Funcionarios::Funcionario> funcionarios;
        
        public:
            void adicionarFuncionario(){
                Shopping::Funcionarios::Funcionario objeto("kauan", 1, "a");
                funcionarios.push_back(objeto);
            }

            void display(){
                funcionarios[0].dispalayInfo();
            }
        };

    };

    namespace Clientes {

    };

};

int main(){

    

    return 0;
}