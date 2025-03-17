#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void get_strings(char** strings, int n);						// get_strings함수 정의
void print_strings(char** strings, int n);						// print_strings함수 정의

int main(void) {
	int n;
	char** strings;
	printf("문자열의 개수: ");
	scanf("%d", &n);											// 문자열의 개수 입력
	strings = (char **)malloc(n * sizeof(char*));				// n개 만큼 동적 메모리 할당
	for (int i = 0; i < n; i++) {
		strings[i] = (char*)malloc(100 * sizeof(char));			// 각각 100만큼 동적 메모리 할당
		if (strings[i] == NULL) {
			printf("동적 메모리 할당 오류");					// 에러 메세지 출력
			exit(1);
		}
	}
	get_strings(strings, n);									// get_strings함수 실행
	print_strings(strings, n);									// print_strings함수 실행
	free(strings);												// 할당된 메모리 반환
	return 0;
}

void get_strings(char** strings, int n) {
	for (int i = 0; i < n; i++) {
		printf("문자열을 입력하시오: ");
		scanf("%s", strings[i]);								// n개 만큼 문자열 입력
	}
}

void print_strings(char** strings, int n) {
	printf("### 입력된 문자열:\n{");							// 헤딩 출력
	for (int i = 0; i < n-1; i++) {
		printf("\"%s\", ", strings[i]);							// 입력된 문자열 출력
	}
	printf("\"%s\"}", strings[n-1]);
}