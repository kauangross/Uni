#include <stdio.h>

typedef struct{
    char Nome[30];
    char SegundoNome[10];
    char TercNome[10];
    int Pop;
    float Pib;
} Municipios;

int main()
{
    FILE *arq;  
    arq = fopen("cidades.txt", "r");
    if (arq == NULL)
    {
        printf("\nERRO AO ABRIR O ARQUIVO!\n");
    }
    Municipios municipio[20];
    int j = 0;

    while (j < 14)
    {
        
        if (fscanf(arq, "%49[^\t] %d %lf\n", municipio[j].Nome, municipio[j].Pop, municipio[j].Pib) == 3)
        {
            j++;
        }
        
    }
    

    /*while ((fscanf(arq, "%s %s %d %f", municipio[j].Nome, municipio[j].SegundoNome, &municipio[j].Pop, &municipio[j].Pib) == 4) || (fscanf(arq, "%s %d %f", municipio[j].Nome, &municipio[j].Pop, &municipio[j].Pib) == 3) || (fscanf(arq, "%s %s %s %d %f", municipio[j].Nome, municipio[j].SegundoNome, municipio[j].TercNome, &municipio[j].Pop, &municipio[j].Pib) == 5))
    {
        j++;
    }*/
    fclose(arq);
    

    /*
    printf("%s %s\n", municipio[0].Nome, municipio[0].SegundoNome);
       
    printf("%s\n", municipio[1].Nome);

    printf("%s %s %s\n", municipio[9].Nome, municipio[9].SegundoNome, municipio[9].TercNome);
    */
    

    return 0;
}
