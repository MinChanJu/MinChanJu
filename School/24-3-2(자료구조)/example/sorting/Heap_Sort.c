#include <stdio.h>

void heap_sort(int array[], int size);
void adjust(int array[], int root, int size);
void printArray(int array[], int size);

int main() {
    int array[] = { 4, 9, 8, 2, 5, 1, 7, 6, 3};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    heap_sort(array, size);
    printArray(array, size);
}

void heap_sort(int array[], int size) {
    for (int i = (size-1)/2; i >= 0; i--) adjust(array, i, size);

    for (int idx = size-1; idx > 0 ; idx--) {
        int tmp = array[0];
        array[0] = array[idx];
        array[idx] = tmp;

        adjust(array, 0, idx);
    }
}

void adjust(int array[], int root, int size) {
    int tmp = array[root];
    int child = root*2+1;
    while (child < size) {
        if (child < size-1 && array[child] < array[child+1]) child++;
        if (tmp <= array[child]) {
            array[(child-1)/2] = array[child];
            child = child*2+1;
        } else break;
    }
    array[(child-1)/2] = tmp;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}