#include <stdio.h>

void quantidade_digitos(int n)
{
    int cont = 0;
    while (n > 0)
    {
        n = n / 10; // Divide por 10, no caso, reduz o número de casas de um número até que ele seja menor q zero.
        cont++;    //  EX: 200 / 10 = 20 -> 20 / 10 = 2 -> 2 / 10 = 0,2 -> Menor que zero, para de contar.
                  //   Ou seja, dividiu 3 vezes, são 3 dígitos.
    }
    printf("%d", cont);
}

int main()
{
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    quantidade_digitos(num);

    return 0;
}
