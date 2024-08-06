#include <stdio.h>
#include <string.h>
#include <ctype.h>

char SeparaPalavra(char fraseI[]){
    char fraseP[100];
    int i = 0;
    int tamF2 = 0;
    int tamI, tamF = 0;
    tamI = strlen(fraseI); 
    for (int k = 0; k < tamI; k++)
    {
        if (isupper(fraseI[k]))
        {
            tamF++;
        }
    }
    tamF += (tamI - 1);
    //printf("Tamanho i: %d\nTamanho f: %d\n", tamI, tamF);
    
    char aux, aux2;
    strcpy(fraseP, fraseI);
    //printf("%s", fraseP);

    while (i < (tamF + tamF2))
    {
        //printf("\n%d\n", i);
        if (isupper(fraseP[i])) {
            if (i != 0) // Para não adicionar espaço na primeira posição;
            {
                //printf("\n%s\n", fraseP);
                aux = fraseP[i];
                fraseP[i] = ' ';
                
                for (int j = (i+1); j < (tamF - 1); j++)
                {
                    aux2 = fraseP[j];
                    fraseP[j] = aux; 
                    aux = aux2;
                }
                i++;
                tamF2++;
            }
        }
        i++;
    }
    
    printf("\n%s\n", fraseP);
    return fraseP[100];
}

int main()
{
    char fraseI[/*100*/] = "VouPassarEmFundamentosDeProgramacao";
    //fgets(fraseI, 100, stdin);
    char fraseP[100]; 
    fraseP[100] = SeparaPalavra(fraseI);

    return 0;
}
