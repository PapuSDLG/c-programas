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

bool isPalindrome(int n) {
    // 5231 = 12345
    int cantCifras = cantidadCifras(n), fakeCifras = cantCifras;
    int number = n, reverso = 0;
    for (int i = 0; i < cantCifras; i++) {
        int digito = number % 10;
        reverso += digito * (int)pow(10, fakeCifras - 1);
        fakeCifras--;
        number /= 10;
    }
    if (reverso == n) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if(isPalindrome(n)) {
        printf("Es palindromo!\n");
    }
    else {
        printf("No es palindromo!\n");
    }
    return 0;
}