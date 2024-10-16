#include <iostream>
using namespace std;

class Moeda {
public:
    float valor;
public:
    
    Moeda(float v): valor(v){}

    Moeda(int v): valor(v){}

    operator auto() const {
        return valor;
    }

};


int main(){
    float n = 20.9;
    Moeda moeda1 = 10;
    Moeda moeda2(n);

    cout << moeda1.valor << endl << moeda2.valor;
    //int x = moeda2.valor; 
    
    int x = moeda1;

    float y = moeda2;    

    cout << endl << x << endl << y << endl;

    Moeda moeda3 = x;
    cout << moeda3.valor;

    moeda3 = y;
    cout << endl << moeda3.valor;
    return 0;
}