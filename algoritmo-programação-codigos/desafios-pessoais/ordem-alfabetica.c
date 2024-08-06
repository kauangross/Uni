#include <stdio.h>

int main()
{
    char nome1[] = "julia";
    char nome2[] = "ana";

    if (nome1[0] < nome2[0])
    {
        printf("%s", nome1);
    }
    if (nome2[0] < nome1[0])
    {
        printf("%s", nome2);
    }
    
    

    return 0;
}
