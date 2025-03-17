#define CRT_SECURE_NO_WARNNINGS
#include <stdio.h>
#define SIZE 10

void print_array(int arr[], int size);
int compare_array(int arr1[], int arr2[], int size);
int copy_array(int arr1[], int arr2[], int size);

int main(void) {
	int a[SIZE] = { 8,7,1,2,5,9,10,3,4,6 };
	int b[SIZE] = { 6,3,1,5,7,10,2,4,8,9 };
	int c[SIZE];

	printf("�迭 a:");
	print_array(a, SIZE);
	printf("�迭 b:");
	print_array(b, SIZE);

	if (compare_array(a, b, SIZE) == 1) {
		printf("�迭 a�� b�� �����ϴ�.\n");
	}
	else {
		printf("�迭 a�� b�� �ٸ��ϴ�.\n");
	}

	copy_array(c, b, SIZE);
	printf("�迭 b:");
	print_array(b, SIZE);
	printf("�迭 c:");
	print_array(c, SIZE);

	if (compare_array(b, c, SIZE) == 1) {
		printf("�迭 b�� c�� �����ϴ�.\n");
	}
	else {
		printf("�迭 b�� c�� �ٸ��ϴ�.\n");
	}

	return 0;
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

int compare_array(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}
	return 1;
}

int copy_array(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = arr2[i];
	}
}