#include <stdio.h>
#define SIZE 10

void print_array(int* arr, int size);
void double_array(int* arr1, int* arr2, int size);

int main(void) {
	int a[SIZE] = { 10,4,3,8,5,7,6,9,2,1 };
	int b[SIZE] = { 0 };

	printf("배열 a: ");
	print_array(&a, SIZE);
	printf("배열 b: ");
	print_array(&b, SIZE);

	double_array(&a, &b, SIZE);

	printf("복사 후 배열 a: ");
	print_array(&a, SIZE);
	printf("복사 후 배열 b: ");
	print_array(&b, SIZE);

	return 0;
}

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *arr++);
	}
	printf("\n");
}

void double_array(int* arr1, int* arr2, int size) {
	for (int i = 0; i < size; i++) {
		if ((*arr1) % 2 == 0) {
			*arr2++ = (*arr1++) * 2;
		}
		else {
			*arr2++ = *arr1++;
		}
	}
}