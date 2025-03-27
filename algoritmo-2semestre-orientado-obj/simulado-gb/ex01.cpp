#include <iostream>
#include <stack>
using namespace std;

void soma(stack<int>& operandos){
    int resultado;
    
    resultado = operandos.top();
    operandos.pop();
    operandos.top() += resultado;
}

int main(){
    stack<int> operandos;
    int resp;
    char op;

    // Adiciona os primeiros numeros
    cin >> resp; 
    operandos.push(resp);

    // Faz as operações
    while (op != '='){
        fflush(stdin);
        cin >> resp;
        operandos.push(resp);
        cin >> op;

        if (op == '+'){
            soma(operandos);
        }

        cout << "deseja encerar?";
        cin >> op;
    }

    while (!operandos.empty()){
        cout << endl << operandos.top();
        operandos.pop();
    }

    return 0;
}