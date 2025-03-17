#include <stdio.h>

void quick_sort(int array[], int left, int right);
void printArray(int array[], int size);

int main() {
    int array[] = { 4, 9, 8, 2, 5, 1, 7, 6, 3};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    quick_sort(array, 0, size-1);
    printArray(array, size);
}

void quick_sort(int array[], int left, int right) {
    if (left >= right) return;
    int i = left, j = right+1;
    int pivot = array[i];
    do {
        do i++; while (array[i] < pivot);
        do j--; while (array[j] > pivot);
        if (i < j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    } while (i < j);
    int tmp = array[j];
    array[j] = array[left];
    array[left] = tmp;

    quick_sort(array, left, j-1);
    quick_sort(array, j+1, right);
    
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}