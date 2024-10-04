#include <iostream>
using namespace std;

class Condicionador{
private:
    int potencia;
    double var_temp = 1.8;
    //double max_temp = 18;
    double temp_ext;
public:
    void setdados(int p, double t){
        potencia = p;
        temp_ext = t;
    }

    double calcular_temp(){
        double temperatura_ambiente;

        temperatura_ambiente = temp_ext - (var_temp * potencia);

        return temperatura_ambiente;
    }
};


int main(){
    Condicionador condicionador1, condicionador2;

    double temp1, temp2;

    condicionador1.setdados(5, 25);
    temp1 = condicionador1.calcular_temp();

    condicionador2.setdados(10, 31);
    temp2 = condicionador2.calcular_temp();

    cout << "1: " << temp1 << endl << "2: " << temp2;

    return 0;
}