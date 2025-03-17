#include <stdio.h>

void insertion_sort(int array[], int size);
void insert(int array[], int tmp, int j);
void printArray(int array[], int size);

int main() {
    int array[] = { 4, 9, 8, 2, 5, 1, 7, 6, 3};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    insertion_sort(array, size);
    printArray(array, size);
}

void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        insert(array, array[i], i);
    }
}

void insert(int array[], int tmp, int j) {
    while (j > 0 && array[j-1] > tmp) {
        array[j] = array[j-1];
        j--;
    }
    array[j] = tmp;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}