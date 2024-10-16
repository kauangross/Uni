#include <iostream>
using namespace std;
#include <vector>

class Forma {
private:
    float area;
public:
    virtual void calcular_area(){
        cout << area << endl;
    }
};

class Quadrado: public Forma {
private:
    float lado;
    float area;
public:
    Quadrado(float l): lado(l){} 
    ~Quadrado(){}

    void calcular_area() override{
        area = lado * lado;
        cout << area << endl;
    }   
};

class Circulo: public Forma {
private:
    float raio;
public:
    Circulo(float r): raio(r){} 
    ~Circulo(){}

    void calcular_area() override{
        cout << 3.14 * raio * raio << endl;
    }
};

int main(){
    vector<Forma*> formas;

    formas.push_back(new Quadrado(2));
    formas.push_back(new Circulo(2));

    for (const auto& it : formas)
    {
        it->calcular_area();
    }
    
    for (auto& it : formas)
    {
        delete it;
    }
    

    return 0;
}