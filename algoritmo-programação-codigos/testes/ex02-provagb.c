#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char Marca[20];
    char Modelo[20];
    int ano;
    int tanque;
    float consumo;
    float autonomia;
    char ultima_letra;
}  veiculos;

int main()
{
    FILE *arq; // ponteiro do tipo arquivo
    arq = fopen("veiculos.txt", "r"); // abertura do arquivo
    veiculos veiculo[20]; 
    int qnt_veiculos = 0;
    int maior_autonomia, menor_autonomia;

    if (arq == NULL) // verificação
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
  
    while (fscanf(arq, "%s %s %d %d %f", veiculo[qnt_veiculos].Marca, veiculo[qnt_veiculos].Modelo, &veiculo[qnt_veiculos].ano, &veiculo[qnt_veiculos].tanque, &veiculo[qnt_veiculos].consumo) == 5)
    {
        qnt_veiculos++;
    }

    fclose(arq);

    printf("\nVeiculos fabricados entre 2015 e 2018:\n");
    for (int i = 0; i < qnt_veiculos; i++)
    {
        if (veiculo[i].ano >= 2015 && veiculo[i].ano <= 2018)
        {
            printf("%s %s\n", veiculo[i].Marca, veiculo[i].Modelo);
        }
    }

    printf("\n\nVeiculos que iniciam com vogal ou terminam com consoante:\n");
    for (int i = 0; i < qnt_veiculos; i++)
    {
        veiculo[i].ultima_letra = veiculo[i].Modelo[strlen(veiculo[i].Modelo)-1]; // Passa a ultima letra dos veículos 
        if (veiculo[i].Modelo[0] == 'A' || veiculo[i].Modelo[0] == 'E' || veiculo[i].Modelo[0] == 'I' || veiculo[i].Modelo[0] == 'O' || veiculo[i].Modelo[0] == 'U')
        { // verifica se começa com vogal
            printf("Comeca com vogal: %s\n", veiculo[i].Modelo);
        } else if ((veiculo[i].ultima_letra != 'a') && (veiculo[i].ultima_letra != 'e') && (veiculo[i].ultima_letra != 'i') && (veiculo[i].ultima_letra != 'o') && (veiculo[i].ultima_letra != 'u') && isalpha(veiculo[i].ultima_letra))
        { // verifica se termina com consoante
            printf("Termina com consoante: %s\n", veiculo[i].Modelo);
        }
        veiculo[i].autonomia = veiculo[i].tanque * veiculo[i].consumo; // calcular a autonomia
    }
    
    for (int i = 0; i < (qnt_veiculos - 1); i++)
    {
        for (int j = (i+1); j < qnt_veiculos; j++)
        {
            if (veiculo[i].autonomia > veiculo[j].autonomia)
            {
                maior_autonomia = i;   
            }
            if (veiculo[i].autonomia < veiculo[j].autonomia)
            {
                menor_autonomia = i;
            }   
        }
    }
    
    printf("\n\nMenor autonomia: %s %s\nAutonomia:%f\n\n", veiculo[menor_autonomia].Marca, veiculo[menor_autonomia].Modelo, veiculo[menor_autonomia].autonomia);
    printf("Maior autonomia: %s %s\nAutonomia:%f\n\n", veiculo[maior_autonomia].Marca, veiculo[maior_autonomia].Modelo, veiculo[maior_autonomia].autonomia);
    return 0;
}
