#include <stdio.h>

void bubble_sort(int array[], int size);
void printArray(int array[], int size);

int main() {
    int array[] = { 4, 9, 8, 2, 5, 1, 7, 6, 3};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    bubble_sort(array, size);
    printArray(array, size);
}

void bubble_sort(int array[], int size) {
    for (int i = size-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}