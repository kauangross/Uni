#include <stdio.h>

void teste(int var, int *ptr){
    printf("Agora x vale %d  (ponteiro)\n", *ptr);
    printf("Agora x vale %d  (variavel x)\n", var);
}

int main()
{
    int x;
    int *p;

    x = 10;
    p = &x;   

    teste(x, p);

    *p = 20;

    teste(x, p);
    
    return 0;
}