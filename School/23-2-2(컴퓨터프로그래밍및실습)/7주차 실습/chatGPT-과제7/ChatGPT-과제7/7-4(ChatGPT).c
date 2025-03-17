#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(int* arr, int size);
int search(int* arr, int size, int x);

int main() {
    int data[] = { 12, 18, 24, 30, 43, 52, 65, 76, 88, 91 };
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array data: ");
    print_array(data, size);

    while (1) {
        int value;
        printf("Enter an integer to search (-1 to quit): ");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }
        else {
            int index = search(data, size, value);
            if (index != -1) {
                printf("%d is at index %d.\n", value, index);
            }
            else {
                printf("%d is not in the array.\n", value);
            }
        }
    }

    return 0;
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *arr);
        arr++;  // ������ �ּҸ� �������� ���� ��ҷ� �̵�
    }
    printf("\n");
}

int search(int* arr, int size, int x) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // �߰ߵ� ��� �ε����� ��ȯ
        }

        if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // �߰ߵ��� ���� ��� -1�� ��ȯ
}
