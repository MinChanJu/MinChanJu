#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void cal_sub_div(int x, int y, int* psub, int* pdiv);

int main(void) {
	int sub, div;
	int num1, num2;

	printf("두 정수를 입력하시오: ");
	scanf("%d %d", &num1, &num2);

	cal_sub_div(num1, num2, &sub, &div);
	printf("두 정수의 뺄셈: %d", sub);
	printf("\n두 정수의 나눗셈: %d", div);

	return 0;
}

void cal_sub_div(int x, int y, int *psub, int *pdiv) {
	int sub, div;
	sub = x - y;
	div = x / y;
	*psub = sub;
	*pdiv = div;
}