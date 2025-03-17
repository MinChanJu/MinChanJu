#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define GET_BIT(n,pos)	(((n) >> (pos)) & 0x01)								// n의 pos번째 비트를 반환하는 매크로
#define SET_BIT(n,pos)	((n) |= (0x01 << (pos)))							// n의 pos번째 비트를 1로 바꾸는 매크로
#define CLR_BIT(n,pos)	((n) &= ~(0x01 << (pos)))							// n의 pos번째 비트를 0으로 바꾸는 매크로

int main(void) {
	int n = 0x00000e05;																	// n의 초기값 설정
	printf("n = %#010X\n", n);															// n 출력
	int pos;
	printf("n에서 확인할 비트의 위치를 입력하시오(0 - 31에서 입력): ");
	scanf("%d", &pos);
	printf("GET_BIT(n,%d)의 결과: %d\n", pos, GET_BIT(n, pos));							// n의 pos번째 비트 출력
	printf("n에서 1로 설정할 비트의 위치를 입력하시오(0 - 31에서 입력): ");
	scanf("%d", &pos);
	SET_BIT(n, pos);																	// n의 pos번째 비트를 1로 변환
	printf("SET_BIT(n,%d)의 결과: %#010X\n", pos, n);									// n 출력
	printf("n에서 0로 설정할 비트의 위치를 입력하시오(0 - 31에서 입력): ");
	scanf("%d", &pos);
	CLR_BIT(n, pos);																	// n의 pos번째 비트를 0으로 변환
	printf("CLR_BIT(n,%d)의 결과: %#010X", pos, n);										// n 출력
	return 0;
}