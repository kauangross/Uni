#include <iostream>
#include "arvorebinaria.h"
#include <vector>
using namespace std;

//g++ main.cpp arvorebinaria.cpp -o main.exe
// main.exe

int main() {
    binarytree arvore;
    int resposta = 0;

    cout << "=========== ARVORE BINARIA ===========" << endl;

    arvore.menu();
    cin >> resposta;
    arvore.UnidadeControle(resposta);

    while(resposta != 0){
        arvore.menu();
        cin >> resposta;
        arvore.UnidadeControle(resposta);
    }

    return 0;
}