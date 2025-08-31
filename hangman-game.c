// El juego del ahorcado

/*
1. Palabra para el ahorcado (HECHO)
2. Contador de vidas (HECHO)
3. la cantidad de letras de la palabra que empiecen con _ (HECHO)
4. Por cada letra fallida se disminuye la cantidad de vidas (HECHO) 
5. letra fallida se agregara al almacen (HECHO)
6. solo se permita un caracter
7. Mensaje al ganar (HECHO)

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

void mostrarEquivocaciones(char* array, int indiceEquivocacion) {
    for (int i = 0; i < indiceEquivocacion; i++) {
        printf("%c ", array[i]);
    }
}
int main() {
    char palabra[100] = "colombia";
    char letraIncorrecta[100] = {};
    int vidas = 5, cantidadLetras = cantLetras(palabra);
    char guiones[cantidadLetras];
    guiones[cantidadLetras] = cantGuiones(cantidadLetras, guiones);
    bool hayCoincidencia;
    int letrasAcertadas = 0, equivocadasIndice = 0;
    // Segun la cantidad de letras seran las veces que se imprimira "_"

    // Empieza el juego
    while (vidas > 0) {
        system("clear");
        printf("Tienes %d vidas!\n", vidas);
        for (int i = 0; i < cantidadLetras; i++) {
            printf("%c ", guiones[i]); // Se ira modificando segun cuanto acierte
        }
        printf("\nLetras erroneas: ");
        mostrarEquivocaciones(letraIncorrecta, equivocadasIndice);
        // Si acertaste la palabra
        if (letrasAcertadas == cantidadLetras) {
            system("clear");
            printf("\n%s", palabra);
            printf("\nHas ganado\n");
            break;
        }
        printf("\n");
        char letra;
        
        scanf(" %c", &letra); // se agrega un espacio antes para que no exista doble iteracion
        for (int i = 0; i < cantidadLetras; i++) {
            // Si la letra es igual que reemplace el _ por la letra
            if (letra == palabra[i]) {
                guiones[i] = letra;
                hayCoincidencia = true;
                letrasAcertadas++;
            }
        }
        if (hayCoincidencia == false) {
            letraIncorrecta[equivocadasIndice++] = letra;
            vidas--;
        }
        if (vidas == 0) {
            system("clear");
            printf("Te quedaste sin vidas.\n");
            break;
        }
        hayCoincidencia = false;
    }
    printf("Fin del juego\n");
    return 0;
}