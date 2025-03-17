#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct cont {													// 구조체 선언
	char name[100];
	char email[100];
}CONTACT;

void get_contacts(CONTACT* conts, int n);								// 함수 정의
void print_strings(CONTACT* conts, int n);								// 함수 정의

int main(void) {
	CONTACT* conts;
	int n;
	printf("주소의 개수: ");
	scanf("%d", &n);													// 주소의 개수 입력
	conts = (CONTACT*)malloc(n * sizeof(CONTACT));						// n만큼 동적 메모리 할당
	if (conts == NULL) {
		printf("동적 메모리 할당 오류");								// 에러 메세지 출력
		exit(1);
	}
	get_contacts(conts, n);												// get_contacts 함수 실행
	print_strings(conts, n);											// print_strings 함수 실행
	free(conts);														// 메모리 반환
	return 0;
}

void get_contacts(CONTACT* conts, int n) {
	for (int i = 0; i < n; i++) {
		printf("이름을 입력하시오: ");
		scanf("%s", conts[i].name);										// 이름 입력
		printf("이메일을 입력하시오: ");
		scanf("%s", conts[i].email);									// 이메일 입력
	}
}

void print_strings(CONTACT* conts, int n) {
	printf("==============================================\n");
	printf("이름\t\t이메일\n");											// 헤딩 출력
	printf("==============================================\n");
	for (int i = 0; i < n; i++) {
		printf("%s\t\t%s\n", conts[i].name, conts[i].email);			// 각 이름 이메일 출력
	}
	printf("==============================================");
}