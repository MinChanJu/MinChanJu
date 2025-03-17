#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>

void get_numbers(int* numbers, int n);							// 함수 정의
void print_numbers(int* numbers, int n);						// 함수 정의

int main(void) {
	int count;
	int* numbers;
	printf("정수의 개수: ");
	scanf("%d", &count);										// 정수의 개수 입력
	numbers = (int*)malloc(count * sizeof(int));				// count만큼 동적 메모리 할당
	if (numbers == null) {
		printf("동적 메모리 할당 오류");						// 에러 메세지 출력
		exit(1);
	}

	get_numbers(numbers, count);								// get_numbers함수 실행
	print_numbers(numbers, count);								// print_numbers함수 실행
	free(numbers);												// 할당된 메모리 반환
	return 0;
}

void get_numbers(int* numbers, int n) {
	for (int i = 0; i < n; i++) {
		printf("정수를 입력하시오: ");
		scanf("%d", &numbers[i]);								// n개 만큼 정수 입력
	}
}

void print_numbers(int* numbers, int n) {
	int sum = 0;
	printf("### 입력된 정수: ");
	for (int i = 0; i < n; i++) {
		printf("%d ",numbers[i]);								// 입력된 정수 출력
		sum += numbers[i];										// 출력마다 출력되는 정수를 sum 변수에 더함
	}
	printf("\n### 입력된 정수들의 합: %d", sum);				// 입력된 정수들의 합 sum 출력
}