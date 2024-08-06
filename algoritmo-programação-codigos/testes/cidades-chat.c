#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUNICIPIOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int populacao;
    double pib;
} Municipio;

void lerArquivo(const char* nomeArquivo, Municipio municipios[], int* n) {
    FILE* file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    *n = 0;
    while (fscanf(file, "%49[^\t] %d %lf\n", municipios[*n].nome, &municipios[*n].populacao, &municipios[*n].pib) == 3) {
        (*n)++;
    }

    fclose(file);
}

void nomesSimples(Municipio municipios[], int n) {
    printf("Municipios com nome simples:\n");
    for (int i = 0; i < n; i++) {
        if (strchr(municipios[i].nome, ' ') == NULL) {
            printf("%s\n", municipios[i].nome);
        }
    }
}

void populacaoFiltro(Municipio municipios[], int n) {
    printf("\nMunicipios com populacao < 22000 ou > 41000:\n");
    for (int i = 0; i < n; i++) {
        if (municipios[i].populacao < 22000 || municipios[i].populacao > 41000) {
            printf("%s: %d\n", municipios[i].nome, municipios[i].populacao);
        }
    }
}

void pibPerCapita(Municipio municipios[], int n) {
    printf("\nMunicipios com PIB per capita entre R$40.000 e R$50.000:\n");
    for (int i = 0; i < n; i++) {
        double pib_per_capita = (municipios[i].pib * 1e6) / municipios[i].populacao;
        if (pib_per_capita >= 40000 && pib_per_capita <= 50000) {
            printf("%s: %.2f\n", municipios[i].nome, pib_per_capita);
        }
    }
}

int main() {
    Municipio municipios[MAX_MUNICIPIOS];
    int n;

    lerArquivo("municipios.txt", municipios, &n);

    nomesSimples(municipios, n);
    populacaoFiltro(municipios, n);
    pibPerCapita(municipios, n);

    return 0;
}