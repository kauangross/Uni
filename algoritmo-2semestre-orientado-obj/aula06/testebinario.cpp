#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream arquivo("../arquivo.bin", ios::binary);

    if (!arquivo.is_open())
    {
        cout << "Erro" << endl;
        return 1;
    }

    char buffer[256];
    arquivo.read(buffer, sizeof(buffer));
    
    arquivo.close();
    return 0;
}