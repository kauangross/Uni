#include <stdio.h>
#include <math.h>

int main()
{
    printf("Elevado\n");
    double base = 2.0;
    double expoente = 3.0;
    double resultado = pow(base, expoente);
    printf("%.1f elevado a %1.f eh %.1f\n", base, expoente, resultado);
    return 0;
}
