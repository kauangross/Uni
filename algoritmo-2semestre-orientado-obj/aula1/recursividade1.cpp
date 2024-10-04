#include <iostream>

int somatorio(int n){
    if(n == 1){
        return 1;
    } else {
        return (n*n) + somatorio(n-1);
    }
}

int main() {
    int n, soma;
    n = 5;
    soma = somatorio(n);
    printf("%d", soma);
    return 0;
}