#include <stdio.h>
#define SIZE 5

void print_array(int* arr, int size);
void merge(int* arr1, int* arr2, int* arr3, int size);

int main(void) {
	int a[SIZE] = { 7,15,34,47,87 };
	int b[SIZE] = { 24,50,59,68,95 };
	int c[2*SIZE];

	printf("배열 a: ");
	print_array(&a, SIZE);
	printf("배열 b: ");
	print_array(&b, SIZE);
	merge(a,b,c, SIZE);
	printf("배열 c: ");
	print_array(&c, 2*SIZE);
	return 0;
}

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *arr++);
	}
	printf("\n");
}

void merge(int* arr1, int* arr2, int* arr3, int size) {
	int i = 0, j = 0, k = 0;
	while (i<size && j<size) {
		if (arr1[i] <= arr2[j]) {
			arr3[k] = arr1[i];
			k++;
			i++;
		}
		else{
			arr3[k] = arr2[j];
			k++;
			j++;
		}
	}
	for (int x=i; x < size; x++) {
		arr3[k] = arr1[x];
		k++;
	}
	for (int x=j; x < size; x++) {
		arr3[k] = arr2[x];
		k++;
	}
}