#include <iostream>
#include "arvorebinaria.h"
using namespace std;

//g++ main.cpp arvorebinaria.cpp -o main.exe
// main.exe

int main() {
    binarytree arvore;
    int resposta = 0;

    cout << "=========== ARVORE BINARIA ===========" << endl;

    int valores[] = {50, 20, 70, 10, 30, 60, 80, 5, 15, 25, 35};
    for (int val : valores) {
        arvore.addnode(val);
    }

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