#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int cantidadCifras(int n) {
    int cantCifras = 0;
    while(n > 0) {
        cantCifras++;
        n /= 10;
    }
    return cantCifras;
}

int reverseInteger(int n) {
    // 5231 = 12345
    bool esNegativo = false;
    if (n < 0) {
        n *= -1;
        esNegativo = true;
    }
    int cantCifras = cantidadCifras(n), fakeCifras = cantCifras;
    int number = n, reverso = 0;
    for (int i = 0; i < cantCifras; i++) {
        int digito = number % 10;
        reverso += digito * (int)pow(10, fakeCifras - 1);
        fakeCifras--;
        number /= 10;
    }

    if (esNegativo) {
        // Se vuelven negativos
        reverso *= -1;
    }
    return reverso;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("El valor de %d alreves es %d\n", n, reverseInteger(n));
    return 0;
}