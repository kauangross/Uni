#include <iostream>
#include <algorithm>
using namespace std;

class Fracao {
private:
    int numerador;
    int denominador;

public:
    Fracao(int n, int d) : numerador(n), denominador(d){
    } 

    ~Fracao(){}

    Fracao operator+(const Fracao &f){
        int aux_numerador, aux_denominador;

        aux_denominador = (denominador * f.denominador); 
        aux_numerador = ((aux_denominador / denominador) * numerador) + ((aux_denominador / f.denominador) * f.numerador);  

        return Fracao(aux_numerador, aux_denominador);    
    }

    Fracao operator*(const Fracao &f){
        Fracao aux(numerador * f.numerador, denominador * f.denominador);
        return aux;
    }

    void imprime(){
        cout << numerador << " / " << denominador << endl << endl;
    }

    void simplificar(){
        int mdc = __gcd(numerador, denominador);
        numerador /=  mdc; 
        denominador /= mdc; 
    }

    string operator==(const Fracao &f){
        double a = numerador/denominador;
        double b = f.numerador/f.denominador;

        if (a == b)
        {
            return "==";
        } else if (a > b)
        {
            return ">";
        } else
            return "<";

        return 0;
    }
};

int main()
{   
    Fracao fracao1 = {2, 20};
    Fracao fracao2 = {10, 1000};
    
    Fracao fracao3 = {0, 0};

    cout << "Soma: ";
    fracao3 = fracao1 + fracao2;
    fracao3.imprime();

    cout << "Soma simplificado: ";
    fracao3.simplificar();
    fracao3.imprime();


    cout << endl << "Multiplicacao: ";
    fracao3 = fracao1 * fracao2;
    fracao3.imprime();

    cout << "Multiplicacao simplificado: ";
    fracao3.simplificar();
    fracao3.imprime();

    string aux_comp;
    cout << "Comparacao: ";
    aux_comp = fracao1 == fracao2;
    cout << aux_comp;

    return 0;
}