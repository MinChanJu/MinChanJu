#include <stdio.h>

void selection_sort(int array[], int size);
void printArray(int array[], int size);

int main() {
    int array[] = { 4, 9, 8, 2, 5, 1, 7, 6, 3};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    selection_sort(array, size);
    printArray(array, size);
}

void selection_sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (array[min] > array[j]) min = j;
        }
        int tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}