#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <string>

class Produto {
public:
    std::string Nome;
    float Preco;
    int Codigo;

    Produto(std::string nome, int codigo, float preco);
    
    ~Produto();
};

// Declaração da função
void abrirEscrita();

void abrirLeitura();

void Buscar();

#endif // FUNCOES_HPP