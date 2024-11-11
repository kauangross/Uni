#include <iostream>
#include "geometria.hpp"
#include <vector>
#include <math.h>
using namespace std;

Ponto::Ponto(float cordenadaX, float cordenadaY): x(cordenadaX), y(cordenadaY){}; // Implementação do construtor

Ponto::~Ponto(){};

void Ponto::AlterarCoordenadas(float coordenadax, float coordenaday){
    x = coordenadax;
    y = coordenaday;
}

float distancia(Ponto a, Ponto b){
    float x1 = a.getx();
    float x2 = b.getx();
    float y1 = a.gety();
    float y2 = b.gety();

    float distancia = sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );
    //cout << endl << "Distancia entre os pontos: " << distancia << endl;

    return distancia;
}

//void filtragem(vector<Ponto> a){

//}

void Ponto::mostrar(Ponto a){
    cout << "( " << a.x << ", " << a.y << " )";
}