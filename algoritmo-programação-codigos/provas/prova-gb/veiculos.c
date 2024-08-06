#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <ctype.h>

typedef struct {
    char fabricante[20];
    char modelo[20];
    int ano;
    float tanque_max;
    float consumo;
} Veiculo;

int main() {
    Veiculo veiculos[100];
    int i, numero_veiculos = 0;

    FILE *file = fopen("veiculos.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir arquivo veiculos.txt");
        return 1;
    }

    char linha[1024];
    fgets(linha, 1024, file);

    while (fscanf(file, "%s %s %d %f %f", veiculos[numero_veiculos].fabricante, veiculos[numero_veiculos].modelo, &veiculos[numero_veiculos].ano, &veiculos[numero_veiculos].tanque_max, &veiculos[numero_veiculos].consumo) == 5) {
        numero_veiculos++;
    }
    fclose(file);
    printf("Veículos fabricados entre 2015 e 2018:\n");
    for (i = 0; i < numero_veiculos; i++) {
        if (veiculos[i].ano >= 2015 && veiculos[i].ano <= 2018) {
            printf("%s %s\n", veiculos[i].fabricante, veiculos[i].modelo);
        }
    }
    printf("\nModelos que iniciam com vogal ou terminam com consoante:\n");
    for (i = 0; i < numero_veiculos; i++) {
    char primeiro_caractere = veiculos[i].modelo[0];
    char ultimo_caractere = veiculos[i].modelo[strlen(veiculos[i].modelo) - 1];
    if (isalpha(primeiro_caractere) && 
        ((primeiro_caractere == 'A' || primeiro_caractere == 'E' || primeiro_caractere == 'I' || primeiro_caractere == 'O' || primeiro_caractere == 'U') ||
         (ultimo_caractere!= 'A' && ultimo_caractere!= 'E' && ultimo_caractere!= 'I' && ultimo_caractere!= 'O' && ultimo_caractere!= 'U' && ultimo_caractere!= 'a' && ultimo_caractere!= 'e' && ultimo_caractere!= 'i' && ultimo_caractere!= 'o' && ultimo_caractere!= 'u'))) {
        printf("%s\n", veiculos[i].modelo);
    }
   }
    float menor_autonomia = INFINITY;
    float maior_autonomia = -INFINITY;
    int indice_menor_autonomia = -1;
    int indice_maior_autonomia = -1;
    for (i = 0; i < numero_veiculos; i++) {
        float autonomia = veiculos[i].tanque_max * veiculos[i].consumo; 
        if (autonomia < menor_autonomia) {
            menor_autonomia = autonomia;
            indice_menor_autonomia = i;
        }
        if (autonomia > maior_autonomia) {
            maior_autonomia = autonomia;
            indice_maior_autonomia = i;
        }
    }

    printf("\nVeículos com menor e maior autonomia:\n");
    printf("Menor autonomia: %s %d - Autonomia: %.2f km\n", veiculos[indice_menor_autonomia].modelo, veiculos[indice_menor_autonomia].ano, menor_autonomia);
    printf("Maior autonomia: %s %d - Autonomia: %.2f km\n", veiculos[indice_maior_autonomia].modelo, veiculos[indice_maior_autonomia].ano, maior_autonomia);

    return 0;
}