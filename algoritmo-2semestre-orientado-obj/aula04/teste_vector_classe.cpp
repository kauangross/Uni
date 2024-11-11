#include <iostream>
using namespace std;
#include <vector>

class C{
public:
    C(){
        std::cout << "instanciada" << std::endl;
    }
};

// Utilizando um vetor que armazena ponteiros do tipo classe
int main(){
    vector<C*> *class_vec = new vector<C*>(); // cria um vetor de classes C
    C *my_class = new C();
    class_vec->push_back(my_class); // adiciona a classe na lista

    C objeto;

    vector<C> vetor;
    vetor.push_back(objeto);
}

/*
// Vetor que armazena classes
int main(){
    vector<C> class_vec; // cria um vetor de classes C
    C my_class;
    class_vec.push_back(my_class); // adiciona a classe na lista

    my_class = class_vec[0]; // retorna a primeira classe inserida na lista
}

*/