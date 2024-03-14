#include <stdio.h>
#include <stdlib.h>

int main()
{
    int indice = 0;
    float max;
    int vet = 0;
    max = vet[0];
    for(int i=1; i<5; i++)
    {
        if( vet[i] > max )
        {
            max = vet[i];
            indice = i;
        }
    }
    printf("O maior valor é %f, na posicao %d", max, indice);
}
