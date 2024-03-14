#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double delta, x1, x2;

    printf("Digite os coeficientes:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    delta = b*b - 4*a*c;
    x1 = (-b + sqrt(delta)) /2 * a;
    x2 = (-b - sqrt(delta)) /2 * a;

    printf("%lf %lf", x1, x2);

    return 0;
}
