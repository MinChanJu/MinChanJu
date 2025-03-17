#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mt_mult(int num);

int main(void) {
	int n;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);
	printf("1부터 %d까지의 곱: %d",n,my_mult(n));
}

int my_mult(int num) {
	if (num == 1) return 1;
	return num * my_mult(num - 1);
}