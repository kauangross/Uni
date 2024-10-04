#include <iostream>
using namespace std;

class Televisao {
private:
    int Volume = 0;
    int Canal = 0;

public:
    void aumentar_volume(){
        Volume++;
    }

    void abaixar_volume(){
        Volume--;
    }

    void aumentar_canal(){
        Canal++;
    }

    void diminuir_canal(){
        Canal--;
    }

    void escolher_canal(){
        int n;
        cin >> n;
        Canal = n;
    }

    void exibir_som(){
        cout << "Som: " << Volume << endl;
    }

    void exibir_canal(){
        cout << "Canal: " << Canal << endl;
    }
};


int main()
{
    Televisao tv;

    tv.aumentar_volume();
    tv.aumentar_volume();
    tv.exibir_som();
    tv.abaixar_volume();
    tv.exibir_som();

    tv.aumentar_canal();
    tv.aumentar_canal();
    tv.exibir_canal();
    tv.diminuir_canal();
    tv.exibir_canal();

    tv.escolher_canal();
    tv.exibir_canal();

    return 0;
}
