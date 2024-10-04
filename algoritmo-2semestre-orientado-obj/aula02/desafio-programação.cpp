#include <iostream>
using namespace std;

class Pessoa {
private:
    int v;

public:
    Pessoa(int velocidade) : v(velocidade){
    }

    ~Pessoa();

    int getV(){
        return v;
    }
};

class Fugitivo : Pessoa {
protected:
    int D; // Distancia inicial;

public:
    Fugitivo(int VF, int d) : Pessoa(VF), D(12-d) {
    }

    ~Fugitivo();

    int getD(){
        return D;
    }    

    int getVF(){
        int vf = getV();
        return vf;
    }
 };  

class Guarda : Pessoa {
private:
    int D = 12; // 12 milhas ate o fim;

public:
    Guarda(int VG) : Pessoa(VG) {
    }

    ~Guarda();

    int getD(){
        return D;
    }

    int getVG(){
        int vg = getV();
        return vg;
    }
};  

void result(Fugitivo *fugitivo, Guarda *guarda){
    int tempoF, tempoG;
    
    if (fugitivo->getD() >= 15)
    {
        cout << "N";
    } else{
        tempoF = fugitivo->getD() / fugitivo->getVF();

        tempoG = guarda->getD() / guarda->getVG();

        if (tempoG <= tempoF)
        {
            cout << "S";
        } else
            cout << "N";
    }
};

int main()
{
    int d, vf, vg;
    cout << "Distancia inicial do fugitivo e guarda: ";
    cin >> d;
    cout << "Velocidade do fugitivo: ";
    cin >> vf;
    cout << "Velocidade da guarda costeira: ";
    cin >> vg; 

    Fugitivo *fugitivo = new Fugitivo(vf, d);
    Guarda *guarda = new Guarda(vg);

    result(fugitivo, guarda);
    return 0;
}