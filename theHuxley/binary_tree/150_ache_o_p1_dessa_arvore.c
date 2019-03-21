#include <stdio.h>
#include <stdlib.h>

void percorrer(int *array, int height, int *p1, int i, int cont, int resultado, int size) {
    if (cont == height) {
        if (*p1 < resultado) {
            *p1 = resultado;
        }
        return;
    }

    if (i < size) {
        resultado *= array[i];  
    }

    percorrer(array, height, p1, 2 * i, cont + 1, resultado, size);
    percorrer(array, height, p1, (2 * i) + 1, cont + 1, resultado, size);
}

void read() {
    int height;
    scanf("%d", &height);
    int array[height * 3];
    int size = 1;

    while (scanf("%d", &array[size]) != EOF) {
        size++;
    }

    int p1 = 0;
    percorrer(array, height, &p1, 1, 0, 1, size);
    printf("%d\n", p1);
}   

int main() {
    read();
    return 0;
}