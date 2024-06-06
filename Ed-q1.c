/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int array[], int size) {
    int i, j, min_idx;

    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        swap(&array[min_idx], &array[i]);
    }
}

void generateRandomArray(int array[], int size, int lower_limit, int upper_limit) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % (upper_limit - lower_limit + 1)) + lower_limit;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    int lower_limit = 0;
    int upper_limit = 100;
    int array[size];

    srand(time(0));

    generateRandomArray(array, size, lower_limit, upper_limit);

    printf("Array: ");
    printArray(array, size);

    selectionSort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}
