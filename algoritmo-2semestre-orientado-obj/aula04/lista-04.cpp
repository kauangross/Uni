/*
    Classe relógio:
        hora
        minuto
        segundo

        métodos:
            SetHora
            getHora
            Avançar horario
*/

#include <iostream>
using namespace std;

class Relogio {
private:
    int Hora;
    int Minuto;
    int Segundo;

public:
    //Relogio(int hora, int minuto, int segundo): 
    //    Hora(hora), Minuto(minuto), Segundo(segundo)
    //{}

    //~Relogio(){}

    void exibir(){
        cout << Hora << ":" << Minuto << ":" << Segundo << endl;
    }

    void setHora(int hora, int minuto, int segundo){
        Hora = hora; 
        Minuto = minuto; 
        Segundo = segundo;
        cout << "Hora foi atualizada" << endl;

        exibir();

        if (Segundo >= 60)
        {
            Segundo = 0;
            Minuto++;
            if (Minuto >= 60)
            {
                Minuto = 0;
                Hora++;
                if (Hora >= 24)
                {
                    Hora = 0;
                }
            }
        }

        if (Minuto >= 60)
        {
            Minuto = 0;
            Hora++;
            if (Hora >= 24)
            {
                Hora = 0;
            }
        }
        
        if (Hora >= 24)
        {
            Hora = 0;
        }
        exibir();
    }

    void gethora(int *hora, int *minuto, int *segundo){
        *hora = Hora;
        *minuto = Minuto;
        *segundo = Segundo;
    }

    void avancar(){
        Segundo++;
        if (Segundo >= 60)
        {
            Segundo = 0;
            Minuto++;
            if (Minuto >= 60)
            {
                Minuto = 0;
                Hora++;
                if (Hora >= 24)
                {
                    Hora = 0;
                }
            }
        }
        exibir();
    }
};


int main(){
    Relogio relogio;
    int hr, min, sec;

    relogio.setHora(24, 59, 58);

    relogio.gethora(&hr, &min, &sec);
    cout << endl << "MAIN: " << hr << ":" << min << ":" << sec << endl;
    
    relogio.avancar();
    relogio.avancar();
    relogio.exibir();
    return 0;
}