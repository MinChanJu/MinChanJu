#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

void replace_string(char source[], char find[], char replace[], char target[]);

int main(void) {
	char source[SIZE]="";
	char find[SIZE]="";
	char replace[SIZE]="";
	char target[SIZE] = "";

	printf("문자열을 입력하시오: ");
	gets_s(source, SIZE);									//source 배열에 문장을 get_s함수를 이용하여 받음
	printf("찾을 단어: ");
	scanf("%s", &find);										//찾을 단어 find 배열에 저장
	printf("바꿀 단어: ");
	scanf("%s", &replace);									//바꿀 단어 replace 배열에 저장
	replace_string(source, find, replace, target);			//source 배열에서 find를 replace로 변환하여 target 배열에 저장
	printf("변환된 문자열: ");
	puts(target);											//target 배열을 출력
}

void replace_string(char source[], char find[], char replace[], char target[]) {
	char seps[] = "  ,";									//분리자 생성
	char* token = 0;
	token = strtok(source, seps);							//token 분리
	while (token != NULL) {
		if (strcmp(token,find)==0) {
			strcat(target, replace);						//token이 find이면 replace로 변환하여 저장
		}
		else {
			strcat(target, token);							//그렇지 않으면 token 저장
		}
		token = strtok(NULL, seps);							//다음 token 분리
		strcat(target, " ");								//공백 추가
	}
}