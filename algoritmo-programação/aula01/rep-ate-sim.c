#include <stdio.h>

int main()
{

/*    
    int resp;
    do
    {
        printf("Deseja continuar?\n");
        printf("[1] = Sim \n[2] = Nao \n");
        scanf("%d", &resp);
        printf("%d \n", resp);
        
    } while (resp == 1);
    printf("Programa terminado.");
*/

    char resp;
    do
    {
        printf("Deseja continuar?\n");
        scanf("%s", &resp);
        
    } while (resp == "sim");
    printf("Programa terminado.");

    return 0;
}