#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Funcionario {
private:
    int Id;
    string Nome; 
    float Salario;

public:
    Funcionario(int id, string nome, float salario)
        : Id(id), Nome(nome), Salario(salario){}
    
    string paraString(){
        string info;

        info = to_string(Id) + "," + Nome + "," + to_string(Salario);

        return info;
    }

    void exibir(){
        cout << "ID: " << Id << "| Nome: " << Nome << "| Salario: " << Salario << endl;
    }
};

class sistemaFuncionario {
private:
    vector<Funcionario> funcionarios;

public:
    void adicionarFuncionario(){
        int id;
        string nome;
        float salario;

        cout << endl << "Digite o ID do funcionario: ";
        cin >> id;
        fflush(stdin);
        cout << "Digite o nome do funcionario: ";
        getline(cin, nome);
        fflush(stdin);
        cout << "Digite o salario do funcionario: ";
        fflush(stdin);
        cin >> salario;

        Funcionario funcionario(id, nome, salario);
        funcionarios.push_back(funcionario);

        cout << endl << "Funcionario adicionado com sucesso!";
    }

    void listarFuncionarios(){
        cout << endl << "Lista de Funcionarios: " << endl;
        for (auto& ptr : funcionarios){
            ptr.exibir();
        }
    }

    void salvarEmArquivo(string nomeArquivo){
        ofstream arquivo(nomeArquivo);
        if(!arquivo.is_open()){
            cout << "Erro ao abrir o arquivo!" << endl;
            return;
        } 

        for (auto& ptr : funcionarios){
            arquivo << ptr.paraString() << "\n";
        }  

        arquivo.close();
        cout << endl << "Funcionarios salvos com sucesso" << endl;
    }
};

void menu();

int main(){
    sistemaFuncionario sistema;
    string nomeArquivo;

    int r = 0;
    while (r != 4){
        cout << endl;
        menu();
        cin >> r;
        switch (r)
        {
        case 1: // Adicionar Funcionario
            sistema.adicionarFuncionario();
            break;
        case 2: // Listar funcionarios
            sistema.listarFuncionarios();
            break;
        case 3: // Salvar em arquivo
            cout << "Digite o nome do arquivo para salvar: ";
            cin >> nomeArquivo;
            sistema.salvarEmArquivo(nomeArquivo);
            break;
        default: // Sair
            cout << "Saindo...";
            break;
        }
    }
    return 0;
}

void menu(){
    cout << endl <<
            "1. Adicionar Funcionário" << endl << 
            "2. Listar Funcionários" << endl << 
            "3. Salvar Funcionários em Arquivo" << endl <<
            "4. Sair" << endl;
}