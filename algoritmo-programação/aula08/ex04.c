#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void teste_rapido()
{
    int ns1, igm, igg;
    printf("Digite o resultado do teste rapido para dengue (NS1, IgM, IgG).\nSe o teste deu negativo, digite 0.\nSe o teste positivou, digite 1\n");
    printf("Digite o resultado do teste NS1 [0 ou 1]: ");
    scanf("%d", &ns1);
    printf("Digite o resultado do teste IgM [0 ou 1]: ");
    scanf("%d", &igm);
    printf("Digite o resultado do teste IgG [0 ou 1]: ");
    scanf("%d", &igg);

    if (ns1 == 0 && igm == 0 && igg == 1)
    {
        printf("Provavel infeccao previa.\n");
    } else if (ns1 == 1 && igm == 0 && igg == 0)
    {
        printf("Infeccao aguda.");
    } else if (ns1 == 1 && igm == 1 && igg == 0)
    {
        printf("Infeccao aguda.");
    } else if (ns1 == 0 && igm == 0 && igg == 0)
    {
        printf("Dengue improvavel.");
    } else if (ns1 == 1 && igm == 0 && igg == 1)
    {
        printf("Infeccao aguda e provavel. Infeccao previa.");
    }   
}

void teste_elisa() {
    int igm, igg;
    printf("Digite o resultado do teste ElisA (IgM, IgG).\nSe o teste deu negativo, digite 0.\nSe o teste positivou, digite 1\n");
    printf("Digite o resultado do teste IgM [0 ou 1]: ");
    scanf("%d", &igm);
    printf("Digite o resultado do teste IgG [0 ou 1]: ");
    scanf("%d", &igg);

    if (igm == 0 && igg == 1)
    {
        printf("Provavel infeccao previa.\n");
    } else if (igm == 1 && igg == 0)
    {
        printf("Infeccao aguda.");
    } else if (igm == 0 && igg == 0)
    {
        printf("Dengue improvavel.");
    } else if (igm == 1 && igg == 1)
    {
        printf("Infeccao aguda e provavel. Infeccao previa.");
    } 
}

int main()
{
    int tempo;
    printf("Digite o tempo de doença: ");
    scanf("%d", &tempo);
    if (tempo <= 6)
    {
        teste_rapido();
    } else {
        teste_elisa();
    }
    return 0;
}