#include <stdio.h>
#include <stdlib.h>

/*
Dificultad: Facil

Tipo de reto: Greedy

Resolucion: Uso de qsort para ordenar las cajas de mayor a menor segun su 
capacidad. Luego usamos por cada iteracción las caja mas grande para meter
las manzanas, asi hasta que o no haya cajas o manzanas.

Complejidad: O(n + m log m)

n = numero de paquetes de manzanas
m = numero de cajas

*/

// Declaraciones de funciones
int getTotalApples(int *apples,int numApples);
int redistributeApplesIntoBoxes(int *apples, int *boxes,
                                int numApples, int numBoxes);
void printArray(const char *name, int *arr, int size);
int cmpDesc(const void *a, const void *b);

int main() {

    // Prueba 1
    int apples1[3] = {1, 3, 2};
    int boxes1[5]  = {4, 3, 1, 5, 2};

    printf("Caso 1\n");
    printArray("Manzanas", apples1, 3);
    printArray("Cajas", boxes1, 5);

    int result1 = redistributeApplesIntoBoxes(apples1, boxes1, 3, 5);
    printf("Cajas necesarias: %d\n\n", result1);

    // Prueba 2
    int apples2[3] = {5, 5, 5};
    int boxes2[4]  = {2, 4, 2, 7};

    printf("Caso 2\n");
    printArray("Manzanas", apples2, 3);
    printArray("Cajas", boxes2, 4);

    int result2 = redistributeApplesIntoBoxes(apples2, boxes2, 3, 4);
    printf("Cajas necesarias: %d\n", result2);

    return 0;
}

void printArray(const char *name, int *arr, int size) {
    printf("%s: [", name);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/*
Funcion que se insertara en quicksort para ordenar.
    Si y > x devuelve positivo
    Si y < x devuelve negativo
*/
int cmpDesc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return y - x;
}


int redistributeApplesIntoBoxes(int *apples, int *boxes,
                                int numApples, int numBoxes) {
    int totalApples = getTotalApples(apples, numApples);
    int boxesUsed = 0;

    //ordenamos las cajas de mayor a menor
    qsort(boxes, numBoxes, sizeof(int), cmpDesc);

    //ejecutamos el algoritmo hasta que se acaben las cajas o las manzanas
    for (int i = 0; i < numBoxes && totalApples > 0; i++) {
        totalApples -= boxes[i];
        boxesUsed++;
    }

    return boxesUsed;
}

//Obtenemos todas las manzanas 
int getTotalApples(int *apples,int numApples){
    int total = 0;
    
    for (int i = 0; i < numApples; i++){
        total += apples[i];
    }
    return total;
}
