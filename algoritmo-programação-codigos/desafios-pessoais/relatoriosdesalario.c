#include <stdio.h>

typedef struct{
        int cod;
        float salario;
        int tempo;
} Funcionarios;

void ConsultaSalario(Funcionarios funcionario[], int QuantDeFuncionarios);
float MenorSalario(Funcionarios funcionario[], int QuantDeFuncionarios);
void FuncionariosPiso(Funcionarios funcionario[], int QuantDeFuncionarios, float menorsalario);

int main()
{
    int QuantDeFuncionarios;
    printf("Qual o tamanho da equipe? ");
    scanf("%d", &QuantDeFuncionarios);
    
    Funcionarios funcionario[QuantDeFuncionarios];

    int CodAux = 0;
    for (int i = 0; i < QuantDeFuncionarios; i++)
    {
        printf("Salario do funcionario %d: ", (i+1));
        scanf("%f", &funcionario[i].salario);
        //printf("Tempo de empresa: ");
        //scanf("%d", &funcionario[i].tempo);
        CodAux++;
        funcionario[i].cod = CodAux;
    }

    ConsultaSalario(funcionario, QuantDeFuncionarios);
    float menorsalario = MenorSalario(funcionario, QuantDeFuncionarios);
    FuncionariosPiso(funcionario, QuantDeFuncionarios, menorsalario);

    return 0;
}

void ConsultaSalario(Funcionarios funcionario[], int QuantDeFuncionarios){
    float SalarioRef;
    printf("\nCosulta de Salario\nValor maximo do salario: ");
    scanf("%f", &SalarioRef);

    printf("\nSalarios ate o valor solicitado\n");
    for (int i = 0; i < QuantDeFuncionarios; i++)
    {
        if (funcionario[i].salario <= SalarioRef)
        {
            printf("\nCodigo do funcionario: %d\nSalario: %f\n\n", funcionario[i].cod, funcionario[i].salario);
        }
    }
    printf("\nSalarios acima do valor solicitado\n");
    for (int i = 0; i < QuantDeFuncionarios; i++)
    {
        if (funcionario[i].salario > SalarioRef)
        {
            printf("\nCodigo do funcionario: %d\nSalario: %f\n\n", funcionario[i].cod, funcionario[i].salario);
        }
    }
}

float MenorSalario(Funcionarios funcionario[], int QuantDeFuncionarios){
    float menorsalario = funcionario[0].salario;

    for (int i = 1; i < QuantDeFuncionarios; i++)
    {
        if (menorsalario > funcionario[i].salario)
        {
            menorsalario = funcionario[i].salario;
        }  
    }
    printf("Menor salario: %f", menorsalario);
    return menorsalario;
}

void FuncionariosPiso(Funcionarios funcionario[], int QuantDeFuncionarios, float menorsalario){
    printf("\n\nFuncionarios que recebem o piso salarial da empresa:\n");
    for (int i = 0; i < QuantDeFuncionarios; i++)
    {
        if (funcionario[i].salario == menorsalario)
        {
            printf("\nCodigo do funcionario: %d\nSalario: %f\n\n", funcionario[i].cod, funcionario[i].salario);
        }
    }
}