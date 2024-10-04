#include <iostream>

int main()
{
    int n;
    
    std::cout << "Tamanho da turma: " << std::endl;
    std::cin >> n;

    float *notas = new float(n);

    for (int i = 0; i < n; i++)
    {
        std::cout << "Aluno " << i+1 << ": ";
        std::cin >> notas[i];
    }
    std::cout << "Notas" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Aluno " << i+1 << ": " << notas[i] << std::endl;
    }

    delete[] notas;
    return 0;
}
