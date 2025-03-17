#include <stdio.h>

void merge_sort(int array[], int left, int right);
void printArray(int array[], int size);

int main() {
    int array[] = { 4, 9, 8, 2, 5, 1, 7, 6, 3};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    merge_sort(array, 0, size-1);
    printArray(array, size);
}

void merge_sort(int array[], int left, int right) {
    if (left >= right) return;
    
    int mid = (left+right)/2;
    merge_sort(array, left, mid);
    merge_sort(array, mid+1, right);

    int newArray[right-left+1];
    int idx = 0;
    int a = left;
    int b = mid+1;
    while (a <= mid && b <= right) {
        if (array[a] <= array[b]) newArray[idx++] = array[a++];
        else if (array[a] > array[b]) newArray[idx++] = array[b++];
    }

    while (a <= mid) newArray[idx++] = array[a++];
    while (b <= right) newArray[idx++] = array[b++];

    for (int i = 0; i <= right-left; i++) array[i+left] = newArray[i];
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}