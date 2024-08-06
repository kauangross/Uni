#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Fabricante[20];
    char Modelo[20];
    int Ano;
    float tanque;
    float consumo;
} Veiculos;

int main()
{
    Veiculos veiculos[50];
    int numero = 0;
    char line[1024];

    // Ponteiro do tipo arquivo
    FILE *arq; 
    arq = fopen("veiculos.txt", "r"); // Abre o arquivo 

    // Enquanto o fscanf conseguir ler os dados do arquivo e armazenar nas 5 variáveis, ele continua
    while (fscanf(arq, "%s %s %d %f %f", veiculos[numero].Fabricante, veiculos[numero].Modelo, &veiculos[numero].Ano, &veiculos[numero].tanque, &veiculos[numero].consumo) == 5) {
        numero++; // Aumenta o numero de linhas
    }

    fclose(arq); // Fecha o arquivo 

    for (int i = 0; i < numero; i++)
    {
        if (veiculos[i].Ano >= 2015 && veiculos[i].Ano <= 2018)
        {
            printf("%s %s\n", veiculos[i].Fabricante, veiculos[i].Modelo);
        }
    }
    printf("\n\n");
    for (int i = 0; i < numero; i++)
    {
        if (veiculos[i].Modelo[0] == 'A' || veiculos[i].Modelo[0] == 'E' || veiculos[i].Modelo[0] == 'I' || veiculos[i].Modelo[0] == 'O' || veiculos[i].Modelo[0] == 'U')
        {
            printf("%s\n", veiculos[i].Modelo);
        } else if (veiculos[i].Modelo[strlen(veiculos[i].Modelo)-1] != 'A' && veiculos[i].Modelo[strlen(veiculos[i].Modelo)-1] != 'E' && veiculos[i].Modelo[strlen(veiculos[i].Modelo)-1] != 'I' && veiculos[i].Modelo[strlen(veiculos[i].Modelo)-1] != 'O' && veiculos[i].Modelo[strlen(veiculos[i].Modelo)-1] != 'U')
        {
            printf("%s\n", veiculos[i].Modelo);
        }        
    }
    
    
    return 0;
}