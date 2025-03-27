#include <iostream>
using namespace std;
#include <map>
#include <string>

int main(){
    map<int, string> alunos;

    alunos[1] = "kauan";
    alunos[2] = "joao";

    int chave;
    string nome;

    cin >> chave;        

    for (auto it = alunos.begin(); it != alunos.end(); it++){
        cout << it->second << endl;
    }
    
    cout << alunos.find(chave)->second;
        
    if(alunos.count(chave)){
        cout << "achou";
    }

    alunos.clear();
    return 0;
}
