#include <iostream>
#include "geometria.hpp"
#include <vector>
using namespace std;

// Não deu tempo de colocar as fuções no hpp e cpp das funções (dava erro)

void encontrarPontosMaisProximos(vector<Ponto>& pontos){
    float distancia_aux;
    float menor_distancia;
    int indice_ponto1;
    int indice_ponto2;

    distancia_aux = distancia(pontos[0], pontos[1]);
    menor_distancia = distancia_aux; 
    
    for (int i = 0; i < (pontos.size()-1); i++)
    {
        for (int j = i+1; j < (pontos.size()); j++)
        {
            distancia_aux = distancia(pontos[i], pontos[j]);
            cout << "Distancia entre o ponto " << i << " e o ponto " << j << ": " << distancia_aux << endl;
            if (menor_distancia >= distancia_aux)
            {
                menor_distancia = distancia_aux;
                indice_ponto1 = i;
                indice_ponto2 = j;
            }
        }
    }
    cout << endl << endl << "Menor distancia: " << endl << endl;
    pontos[indice_ponto1].mostrar(pontos[indice_ponto1]);
    cout << " e ";
    pontos[indice_ponto2].mostrar(pontos[indice_ponto2]);
};

void filtrandoPontos(vector<Ponto>& pontos, float numx1, float numy1, float numx2, float numy2){
    cout << "Pontos filtrados na regiao: (" << numx1 << ", " << numy1 << ") e (" << numx2 << ", " << numy2 << "):" << endl;
    for (int i = 0; i < pontos.size(); i++)
    {
        if ( ( numx1 <= pontos[i].getx() ) && (numy1 <= pontos[i].gety()) && ( numx2 >= pontos[i].getx() ) && (numy2 >= pontos[i].gety()))
        {
            pontos[i].mostrar(pontos[i]);
            cout << endl;
        }
    }
}

int main()
{
    vector<Ponto> pontos = {Ponto(2.1, 3.4), Ponto(1.0, 2.0), Ponto(4.5, 5.0), Ponto(2.5, 2.5), Ponto(3.5, 4.0), Ponto(0.0, 1.0)};
    
    cout << "Distancias:" << endl;
    encontrarPontosMaisProximos(pontos);
    cout << endl << endl;
    filtrandoPontos(pontos, 2, 2, 5, 5);

    pontos.erase(2);
    
    return 0;
}
