#define CRT_SECURE_NO_WARNNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int find_max(int list[], int n);
int find_min(int list[], int n);

int main(void) {
	int list[SIZE];
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {
		list[i] = rand() % 100 + 1;
	}
	
	printf("배열 list:");
	for (i = 0; i < SIZE; i++) {
		printf(" %d", list[i]);
	}
	printf("\n최대값은 %d", find_max(list, SIZE));
	printf("\n최소값은 %d", find_min(list, SIZE));

	return 0;
}

int find_max(int list[], int n) {
	int i, val=0;

	for (i = 0; i < n; i++) {
		if (val < list[i]) {
			val = list[i];
		}
	}

	return val;
}

int find_min(int list[], int n) {
	int i, val = 101;

	for (i = 0; i < n; i++) {
		if (val > list[i]) {
			val = list[i];
		}
	}

	return val;
}