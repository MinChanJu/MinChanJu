#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

void replace_space(char s[], int n);

int main(void) {
	char str[SIZE];
	printf("문자열을 입력하시오: ");
	gets_s(str, SIZE);					//str 배열에 문장을 get_s함수를 이용하여 받음
	replace_space(str, SIZE);			//str 배열의 공백을 /로 변환하는 함수
	printf("공백이 변경된 문자열: ");
	puts(str);							//변경된 str 배열을 출력
}

void replace_space(char s[], int n) {
	char tmp[SIZE];
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			tmp[i] = '/';				//s[i]가 공백일 경우 /로 변환
		}
		else {
			tmp[i] = s[i];				//그 외에 경우 그대로 복사
		}
	}
	strcpy(s, tmp);						//s에 tmp를 복사
}