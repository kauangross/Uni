#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream arquivo("../arquivo.txt", ios::app);
    string texto;
    cin >> texto;
    arquivo << &texto << endl;

    if (!arquivo.is_open())
    {
        cout << "Erro" << endl;
    }
    arquivo.close();

    ifstream arquivo2("../arquivo.txt");

    if (!arquivo2.is_open())
    {
        cout << "Erro" << endl;
    }

    string linha;
    while (getline(arquivo2, linha))
    {
        cout << linha << endl;
    }

    arquivo.close();

    /*ifstream arquivo2("../arquivo.txt");

    string palavra;
    while (arquivo2 >> palavra)
    {
        cout << palavra << endl;
    }
    arquivo2.close();*/
    return 0;
}