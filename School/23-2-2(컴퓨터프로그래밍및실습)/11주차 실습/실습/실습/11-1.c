#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10
#define INIT_ARRAY(array,size,value) for (int i=0;i<size;i++) array[i] = value+i;			// value로 배열을 초기화하는 매크로 설정

int main(void) {
	int a[SIZE];
	int value;
	printf("배열 초기화를 시작할 정수를 입력하시오: ");
	scanf("%d", &value);
	INIT_ARRAY(a, SIZE, value);												// 입력받은 value로 배열을 초기화
	printf("초기화된 배열 a = [%d", a[0]);
	for (int i = 1; i < SIZE; i++) printf(", %d", a[i]);					// 배열 출력
	printf("]");
}