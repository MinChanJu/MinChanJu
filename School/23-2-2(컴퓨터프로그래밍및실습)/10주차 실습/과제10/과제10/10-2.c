#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void compare_files(FILE* fp1, FILE* fp2);

int main(void) {
	FILE* fp1, *	 fp2;
	char fname1[100], fname2[100];
	printf("첫번째 파일: ");
	scanf("%s", &fname1);
	printf("두번째 파일: ");
	scanf("%s", &fname2);
	fp1 = fopen(fname1, "r");										// 파일 열기
	if (fp1 == NULL) {
		printf("파일 %s를 열 수 없습니다.\n", fname1);				// 에러가 나면 메세지 출력
	}
	fp2 = fopen(fname2, "r");										// 파일 열기
	if (fp2 == NULL) {
		printf("파일 %s를 열 수 없습니다.\n", fname2);				// 에러가 나면 메세지 출력
	}
	compare_files(fp1, fp2);										// 파일 변환

	fclose(fp1);													// 파일 닫기
	fclose(fp2);													// 파일 닫기
}

void compare_files(FILE* fp1, FILE* fp2) {
	char buffer1[1024];
	char buffer2[1024];
	fgets(buffer1, 1024, fp1);
	fgets(buffer2, 1024, fp2);
	while ((buffer1 != NULL) && buffer2 != NULL) {
		if (strcmp(buffer1, buffer2) != 0) {
			printf("<< %s\n", buffer1);
			printf(">> %s\n", buffer2);
		}
		fgets(buffer1, 1024, fp1);
		fgets(buffer2, 1024, fp2);
	}
}