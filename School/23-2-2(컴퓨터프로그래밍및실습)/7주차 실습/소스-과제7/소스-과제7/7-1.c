#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void cal_sub_div(int x, int y, int* psub, int* pdiv);

int main(void) {
	int sub, div;
	int num1, num2;

	printf("�� ������ �Է��Ͻÿ�: ");
	scanf("%d %d", &num1, &num2);

	cal_sub_div(num1, num2, &sub, &div);
	printf("�� ������ ����: %d", sub);
	printf("\n�� ������ ������: %d", div);

	return 0;
}

void cal_sub_div(int x, int y, int *psub, int *pdiv) {
	int sub, div;
	sub = x - y;
	div = x / y;
	*psub = sub;
	*pdiv = div;
}