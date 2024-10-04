#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Funcionario{
public:
    string nome;
    double salarioBase;
public:
    Funcionario(string nom, double salario): nome(nom), salarioBase(salario){}

    ~Funcionario(){}

    void exibir(){
        cout << nome << endl;
        cout << salarioBase << endl;
    }

    void aumentar_salario_base(){
        salarioBase += salarioBase * 0.1;
        this->exibir();
    }
};

class FuncionarioCLT: public Funcionario{
public:
    FuncionarioCLT(string nom, double salario): Funcionario(nom, salario){}

    ~FuncionarioCLT(){}

    void calcularSalario() {
        salarioBase += salarioBase * 0.05;
    }
};

class FuncionarioPJ: public Funcionario {
public:
    FuncionarioPJ(string nom, double salario): Funcionario(nom, salario){};

    ~FuncionarioPJ(){};

    void calcularSalario() {
        salarioBase -= salarioBase * 0.15;
    }
};

int main(){
    string nome;
    double salario;
    int a, qnt_funcionariosCLT = 0, qnt_funcionariosPJ = 0, aux_i = 0, aux_j = 0, aux;

    vector<FuncionarioCLT*> CLT;
    vector<FuncionarioPJ*> PJ;

    //CLT.push_back(new FuncionarioCLT("kauan", 1200));
    //CLT.push_back(new FuncionarioCLT("rafa", 1000));
    
    
     cin >> a;
    do
    {
        switch (a)
        {
        case 1:
            cout << "Funcionario CLT" << endl << "Nome: ";
            fflush(stdin);
            getline(cin, nome);
            cout << "Salario Base: ";
            cin >> salario;
            CLT.push_back(new FuncionarioCLT(nome, salario));
            qnt_funcionariosCLT++;
            break;
        case 2:
            cout << "Funcionario PJ" << endl << "Nome: ";
            fflush(stdin);
            getline(cin, nome);
            cout << "Salario Base: ";
            cin >> salario;
            PJ.push_back(new FuncionarioPJ(nome, salario));
            qnt_funcionariosPJ++;
            break;

        case 3:
            cout << "Funcionarios CLT: " << endl;
            while (aux_i < qnt_funcionariosCLT)
            {
                if (qnt_funcionariosCLT > 0)
                {
                    CLT[aux_i]->exibir();
                    cout << endl;
                }
                aux_i++;
            }
            aux_i = 0;
            cout << endl << endl << "Funcionarios PJ: " << endl;
            while (aux_j < qnt_funcionariosPJ)
            {
                if (qnt_funcionariosPJ > 0)
                {
                    PJ[aux_j]->exibir();
                    cout << endl;
                }
                aux_j++;
            }
            aux_j = 0;
            break;
        case 4:
            cout << "Calcular o salario final:" << endl << "Funcionario CLT ou PJ? [1] ou [2]" ;
            cin >> a;
            cout << "Numero do funcionario: ";
            cin >> aux; 
            
            if (a == 1 && qnt_funcionariosCLT > 0)
            {
                CLT[aux-1]->calcularSalario();
                CLT[aux-1]->exibir();
            }
            if (a == 2 && qnt_funcionariosPJ > 0)
            {
                PJ[aux-1]->calcularSalario();
                PJ[aux-1]->exibir();
            }
            break;
        case 5:
            cout << endl << "Salarios atualizados: " << endl;
            for (int i = 0; i < qnt_funcionariosCLT; i++)
            {
                CLT[i]->aumentar_salario_base();
            }
            for (int i = 0; i < qnt_funcionariosPJ; i++)
            {
                PJ[i]->aumentar_salario_base();
            }
            break;
        default:
            break;
        }
         cin >> a;
    } while (a != 6);
    return 0;
}