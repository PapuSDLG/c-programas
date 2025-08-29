// El juego del ahorcado

/*
1. Palabra para el ahorcado (HECHO)
2. Contador de vidas (HECHO)
3. la cantidad de letras de la palabra que empiecen con _ (HECHO)
4. Por cada letra fallida se disminuye la cantidad de vidas y se agregara al almacen
*/
#include <stdio.h>

int cantLetras(char *str) {
    int contador = 0;
    while(str[contador] != '\0') {
        contador++;
    }
    return contador;
}
int cantGuiones(int cantidadLetras, char *guiones) {
    for (int i = 0; i <  cantidadLetras; i++) {
        guiones[i] = '_';
    }
}
int main() {
    char palabra[100] = "muerte";
    char letraEquivocada[100] = {};
    int vidas = 5, cantidadLetras = cantLetras(palabra);
    char guiones[cantidadLetras];
    guiones[cantidadLetras] = cantGuiones(cantidadLetras, guiones);

    for (int i = 0; i < cantidadLetras; i++) {
        printf("%c ", guiones[i]);
    }
    // Segun la cantidad de letras seran las veces que se imprimira "_"
    // for (int i = 0; i < cantidadLetras; i++) {
    //     printf("%c ", guiones[i]); // Se ira modificando segun cuanto acierte
    
    // }
    // printf("\n");
    // // Empieza el juego
    // while (vidas != 0) {
    //     char letra;
    //     scanf("%c", &letra);
    //     for (int i = 0; i < cantidadLetras; i++) {
    //         // Si la letra es igual que reemplace el _ por la letra
    //         if (letra == palabra[i]) {
    //             guiones[i] = letra;
    //         }
    //     }
    // }
    return 0;
}