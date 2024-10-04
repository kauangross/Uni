#include <iostream>
#include <vector>
#include <cmath> // Para usar sqrt
using namespace std;

class Objeto {
protected:
    vector<float> Posicao;
    vector<float> Vetor;
    float V;

public:
    Objeto(vector<float> posicao, vector<float> vetor, float v): Posicao(posicao), Vetor(vetor), V(v) {}

    virtual ~Objeto() {}

    void posicao_tempo() {
        // Atualiza a posição de acordo com a velocidade e o vetor direção
        Posicao[0] += V * Vetor[0];
        Posicao[1] += V * Vetor[1];
    }

    void exibir() const {
        cout << "Posicao: (" << Posicao[0] << ", " << Posicao[1] << ")" << endl;
    }

    float getPX() const {
        return Posicao[0];
    }

    float getPY() const {
        return Posicao[1];
    }
};

class Quadrado : public Objeto {
private:
    float lado = 5.0f;

public:
    Quadrado(vector<float> posicao, vector<float> vetor, float v): Objeto(posicao, vetor, v) {}

    ~Quadrado() {}

    float getlado() const {
        return lado;
    }
};

class Circulo : public Objeto {
private:
    float raio = 2.0f;

public:
    Circulo(vector<float> posicao, vector<float> vetor, float v): Objeto(posicao, vetor, v) {}

    ~Circulo() {}

    float getraio() const {
        return raio;
    }
};

// Função que verifica colisão entre quadrado e círculo
void colidir(const Quadrado& quadrado, const Circulo& circulo) {
    // Diagonal do quadrado dividido por 2
    float q_d = (quadrado.getlado() * sqrt(2)) / 2;

    // Raio do círculo
    float c_d = circulo.getraio();

    // Distância entre o centro do quadrado e do círculo
    float dx = quadrado.getPX() - circulo.getPX();
    float dy = quadrado.getPY() - circulo.getPY();

    // Verificar se há colisão (a soma das distâncias é maior ou igual à distância real)
    if (c_d + q_d >= sqrt(dx * dx + dy * dy)) {
        cout << "Colisao detectada!" << endl;
        quadrado.exibir();
        circulo.exibir();
        cout << endl;
    }
}