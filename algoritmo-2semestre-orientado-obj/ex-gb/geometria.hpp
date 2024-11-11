#ifndef GEOMETRIA_HPP
#define GEOMETRIA_HPP

class Ponto {
private:
    float x;
    float y;
public:
    Ponto(float cordenadaX, float cordenadaY);

    ~Ponto();

    void AlterarCoordenadas(float coordenadax, float coordenaday);

    void mostrar(Ponto a);

    float getx(){
        return x;
    }

    float gety(){
        return y;
    }
};

float distancia(Ponto a, Ponto b);

#endif