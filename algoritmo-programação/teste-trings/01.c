#include <stdio.h>
#include <string.h>

int main()
{
    // Uma letra
    char letra;
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    printf("%c\n", letra);
    //

    fflush(stdin); // Limpa memória
    printf("\n");

    // Uma frase sem espaço ( NÃO IMPORTA O TAMANHO DO VETOR!!! )
    char frase[10];
    printf("Digite uma frase sem espaco: ");
    scanf("%s", &frase);
    printf("%s\n", frase);
    //

    fflush(stdin); // Limpa memória
    printf("\n");

    // Uma frase com espaço de ate 50 char
    char frase_espaco[50];
    printf("Digite uma frase con espaco: ");
    fgets(frase_espaco, sizeof(frase_espaco), stdin);
    printf("%s\n", frase_espaco);
    //
    return 0;
}
