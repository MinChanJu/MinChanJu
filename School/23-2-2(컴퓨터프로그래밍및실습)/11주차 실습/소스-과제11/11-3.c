#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define GET_BIT(n,pos)	(((n) >> (pos)) & 0x01)								// n의 pos번째 비트를 반환하는 매크로

void print_bits(int value);

int main(void) {
	int n, k, pos, val;
	printf("정수값을 입력하시오: ");
	scanf("%d", &n);
	while (1) {
		printf("왼쪽 이동은 0, 오른쪽 이동은 1을 입력하시오(-1은 Quit) : ");
		scanf("%d", &k);
		if (k == -1) break;															// 입력이 -1이면 끝냄
		printf("이동시킬 비트 수를 입력하시오:");
		scanf("%d", &pos);
		printf("이동 전: ");
		print_bits(n);																// n의 비트 출력
		if (k == 0) {
			for (int i = 0; i < pos; i++) n = n * 2;								// 왼쪽 이동일 경우 2를 pos번 곱합
		}
		else if (k == 1) {
			for (int i = 0; i < pos; i++) n = n / 2;								// 오른쪽 이동일 경우 2를 pos번 나눔
		}
		printf("이동 후: ");
		print_bits(n);																// n의 비트 출력
	}
}

void print_bits(int value) {
	for (int i = 31; i >= 0; i--) {
		if ((i + 1) % 4 == 0) printf(" %d", GET_BIT(value, i));						// 4칸마다 띄어쓰기 하고 출력
		else printf("%d", GET_BIT(value, i));
	}
	printf("\n");
}