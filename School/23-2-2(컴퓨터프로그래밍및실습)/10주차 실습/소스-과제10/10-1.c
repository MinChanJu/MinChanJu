#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_file(FILE* fp);
void convert_to_upper(FILE* fp1, FILE* fp2);

int main(void) {
	FILE* fp1, * fp2;
	char fname1[100], fname2[100];
	printf("첫번째 파일: ");
	scanf("%s", &fname1);
	printf("두번째 파일: ");
	scanf("%s", &fname2);
	fp1 = fopen(fname1, "r");										// 파일 열기
	if (fp1 == NULL) {
		printf("파일 %s를 열 수 없습니다.\n", fname1);				// 에러가 나면 메세지 출력
	}
	fp2 = fopen(fname2, "w+");										// 파일 열기
	if (fp2 == NULL) {
		printf("파일 %s를 열 수 없습니다.\n", fname2);				// 에러가 나면 메세지 출력
	}
	printf("### 원본 파일 ###\n");
	print_file(fp1);												// 원본 파일 출력
	fseek(fp1, 0, SEEK_SET);										// 포인터 위치 변경

	convert_to_upper(fp1, fp2);										// 파일 변환

	printf("\n### 변환된 파일 ###\n");
	fseek(fp2, 0, SEEK_SET);										// 포인터 위치 변경
	print_file(fp2);												// 변환된 파일 출력

	fclose(fp1);													// 파일 닫기
	fclose(fp2);													// 파일 닫기

	return 0;
}

void print_file(FILE* fp) {
	char buffer[256];
	while (fgets(buffer, 256, fp) != NULL) {
		printf("%s",buffer);										// 파일 읽고 출력
	}
}

void convert_to_upper(FILE* fp1, FILE* fp2) {
	int a;
	while ((a = fgetc(fp1)) != EOF) {
		if (a > 90) {												// 소문자면 32를 빼서 대문자로 바꾼 후 출력
			fprintf(fp2, "%c", a - 32);
		}
		else {
			fprintf(fp2, "%c", a);
		}
	}
}