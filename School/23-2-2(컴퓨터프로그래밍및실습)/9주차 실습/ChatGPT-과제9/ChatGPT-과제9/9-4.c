#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(int numbers[], int size);
void find_max_ptr(int numbers[], int size, int** maxp);

int main() {
    int numbers[] = { 32, 42, 82, 12, 22, 52, 62, 92, 72 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Print the array
    printf("배열에 저장된 데이터: ");
    print_array(numbers, size);

    // Find the maximum value and its address
    int* maxp;
    find_max_ptr(numbers, size, &maxp);

    // Print the maximum value
    printf("배열내 가장 큰 값은 %d\n", *maxp);

    return 0;
}

void print_array(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void find_max_ptr(int numbers[], int size, int** maxp) {
    *maxp = &numbers[0];  // Assume the first element is the maximum

    for (int i = 1; i < size; i++) {
        // If the current element is greater than the value at maxp, update maxp
        if (numbers[i] > **maxp) {
            *maxp = &numbers[i];
        }
    }
}