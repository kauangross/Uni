#include <iostream>
using namespace std;

class Livro {
private:
    string titulo;
    string autor;
    int ano;

public:
    void set(string tit, string aut, int a){
        titulo = tit;
        autor = aut;
        ano = a;
    }

    // Destrutor
    ~Livro(){
        cout << "Livro apagado: " << endl;
    }

    void exibir(){
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << ano << endl << endl;
    }
};

int main()
{
    Livro *livro = new Livro[3];
    string titulo_aux;
    string autor_aux;
    int ano_aux;

    for (int i = 0; i < 3; i++)
    {
        cin >> titulo_aux;
        cin >> autor_aux;
        cin >> ano_aux;
        livro[i].set(titulo_aux, autor_aux, ano_aux);
    }
    
    for (int i = 0; i < 3; i++)
    {
        livro[i].exibir();
    }

    delete[] livro;
    return 0;
}

// CONSTRUTOR
/*  
    Livro(string tit, string aut, int a) : titulo(tit), autor(aut), ano(a) {
        cout << "Livro adicionado" << endl;
    }  

    Livro *livros = new Livro("Harry Potter", "aaa", 2000)
*/