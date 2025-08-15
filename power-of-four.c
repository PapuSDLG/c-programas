#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// verificar si es potencia de cuatro

bool isPowerOfFour(double n) {
    while(n > 1) {
        n /= 4;
    }    
    if (n == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    double n;
    scanf("%lf", &n);
    bool verifier = isPowerOfFour(n);
    if(verifier) {
        printf("Es potencia de 4\n");
    }
    else {
        printf("No es potencia de 4\n");
    }
    return 0;
}