#include <stdio.h>


int main()
{
    printf("\n Repetidor: for \n");
    for (int i = 0; i <= 20; i++)
    {
        printf(" %d", i);
    }
    
    printf("\n");
    printf("\n Repetidor: while \n");
    int i = 0;
    while (i <= 20)
    {
        printf(" %d", i);
        i++;
    }
    
    printf("\n");
    printf("\n Repetidor: do-while \n");
    i = 0;
    do
    {
        printf(" %d", i);
        i++;
    } while (i <= 20);
}
