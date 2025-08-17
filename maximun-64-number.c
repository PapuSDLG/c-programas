#include <stdio.h>
#include <stdbool.h>
#include <math.h>
/* Se te da un entero positivo num que consiste solo de los
digitos 6 y 9.
Regresa el numero maximo que obtienes cambiando al menos
un digito (6 se vuelve 9, y 9 se vuelve 6) */

int contadorDigito(int n) {
    int cantDigito = 0, potencia = 1;
    while (n > 0) {
        cantDigito++;
        n /= 10;
    }
    return cantDigito;
}

bool digitosIguales(int n){
    int numero = n, digitoTotal = contadorDigito(n);
    int contadorSeis = 0, contadorNueve = 0;
    int arr[10000] = {};
    for (int i = 0; i < digitoTotal; i++) {
        int digito = numero % 10;
        arr[i] = digito;
        numero /= 10;
    }

    for (int i = 0; i < digitoTotal; i++) {
        if (arr[i] == 6) {
            contadorSeis++;
        }
        else if (arr[i] == 9) {
            contadorNueve++;
        }
    }
    if (contadorSeis == digitoTotal || contadorNueve == digitoTotal) {
        return true;
    }
    else {
        return false;
    }
}
int maximunNumber(int n) {
    int digitoTotal = contadorDigito(n), resultado = 0;
    int numero = n; // Almacenara el valor original de n;

    // Si todos los digitos son 6 o 9
    if (numero == 6) {
        return 9;
    }
    if (digitosIguales(n)) {
        return numero;
    }
    else {
        for (int i = 0; i < digitoTotal; i++) {
            // Obtener los digitos y modificarlos (¿pero como?)
            int digito = n % 10;
            int resultadoTemporal;
            // n +- 3 para poner 6 o 9
            if (digito == 6) {
                resultadoTemporal = numero + (3 * (1 * pow(10, i)));
            }
            else if (digito == 9) {
                resultadoTemporal = numero - (3 * (1 * pow(10, i)));
            }

            if (resultadoTemporal > resultado) {
                resultado = resultadoTemporal;
            }
            n /= 10;
        }
        return resultado;
    }
    
}

int main() {
    int number, numeroMaximo;
    scanf("%d", &number);
    int cantDigito = contadorDigito(number);
    numeroMaximo = maximunNumber(number);
    printf("El numero maximo de los %d digitos es: %d\n", cantDigito, numeroMaximo);
    return 0;
}