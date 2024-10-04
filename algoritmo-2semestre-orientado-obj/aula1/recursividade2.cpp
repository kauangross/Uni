#include <iostream>

int a(int m, int n){
    if(m == 0){
        return n + 1;
    } else if(m > 0 && n == 0){
        return a(m - 1, 1);
    } else {
        return a(m - 1, a(m, n - 1));
    }
}

int main() {
    int valor;
    
    valor = a(3, 2);
    
    printf("%d", valor);
    return 0;
}