#include <iostream>
using namespace std;
#include <stack>

void conversor(int dec){
    stack<int> pilha;

    while (dec > 0){
        pilha.push(dec % 2);
        dec /= 2;
    } 
    
    while(!pilha.empty()){
        cout << pilha.top();
        pilha.pop();
    }
}

int main(){

    conversor(10);

    return 0;
}
