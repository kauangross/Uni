#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> alunos;

    alunos["kauan"] = 1;

    string nome;
    int id;

    for(const auto& [nome, id] : alunos){

    }

    return 0;
}