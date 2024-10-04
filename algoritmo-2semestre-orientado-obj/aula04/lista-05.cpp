#include <iostream>
using namespace std;
#include <math.h>

class Circulo{
private:
    //atributos
    double raio;
    double area;
    double circunferencia;
    int centro_circulo[2];

    //metodos
    void calcular_area(){
        area = 3.14 * (raio * raio); 
    }

    void calcular_distancia(int x, int y){
        int d;
        d = sqrt((centro_circulo[0] - x)*(centro_circulo[0] - x) + (centro_circulo[1] - y)*(centro_circulo[1] - y));
        cout << endl << "Distancia: " << d << endl;
    }

    void calcular_circunferencia(){
        circunferencia = 2 * 3.14 * raio;
    }

public:
    void set_raio(double r){
        raio = r;
    }

    void aumentar_raio(double porcentagem){
        raio += raio * (porcentagem / 100);
    }

    void definir_centro(int x, int y){
        centro_circulo[0] = x;
        centro_circulo[1] = y;
    }

    // imprimir
    void imprimir_raio(){
        cout << endl << "Raio:" << raio;
    }

    void imprimir_centro(){
        cout << endl << "[ " << centro_circulo[0] << ", " << centro_circulo[1] << " ]" << endl; 
    }

    void imprimir_area(){
        calcular_area();
        cout << endl << "Area:" << area << endl;
    }
};


int main()
{
    Circulo circulo;

    circulo.set_raio(2);

    circulo.aumentar_raio(10);

    circulo.imprimir_raio();

    circulo.definir_centro(2, 4);

    circulo.imprimir_centro();

    circulo.imprimir_area();

    

    return 0;
}

/*
    Classe Circulo
        privado:
            Raio
            area
            circunferencia
            centro_circulo[2] - x, y

            metodos: - v
                calcular area - v
                calcular distancia entre centro de 2 circulos - v
                calcular circunferencia - v
        
        publico:
            definir raio - v
            aumentar raio - v
            definir centro (x, y) - v
            imprimir raio - v
            imprimir centro - v
            imprimir area do circulo - v
*/ 