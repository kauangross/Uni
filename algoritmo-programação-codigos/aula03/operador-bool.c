#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool condicao1 = true;
    bool condicao2 = false;

    // Operacao AND (&&)
    bool resultado_and = condicao1 && condicao2;
    printf("Reultado AND: %d\n", resultado_and);

    // Operacao AND (&&)
    bool resultado_or = condicao1 || condicao2;
    printf("Reultado OR: %d\n", resultado_or);
    
    return 0;
}
