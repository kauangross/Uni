#include <stdio.h>
#include <math.h>

int main()
{
    float d, vf, vg, tf, tg, hip;
    printf("Digite a distancia inicial: ");
    scanf("%f", &d);
    printf("Digite a velocidade do fugitivo: ");
    scanf("%f", &vf);
    printf("Digite a velocidade da Guarda: ");
    scanf("%f", &vg);

    hip = sqrt((pow(12, 2)) + (d*d));
    tf = 12 / vf;
    tg = hip / vg;

    if (tf >= tg)
    {
        printf("S");
    } else
    {
        printf("N");
    }
    return 0;
}