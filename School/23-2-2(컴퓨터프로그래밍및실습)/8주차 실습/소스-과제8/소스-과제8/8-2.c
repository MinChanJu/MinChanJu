#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

void make_upper_str(char* s, int n);

int main(void) {
	char str[SIZE];
	printf("문자열을 입력하시오: ");
	gets_s(str, SIZE);					//str 배열에 문장을 get_s함수를 이용하여 받음
	make_upper_str(str, SIZE);			//str 배열의 소문자를 모두 대문자로 변환하는 함수
	printf("변환된 문자열: ");
	puts(str);							//변경된 str 배열을 출력
}

void make_upper_str(char *s, int n) {
	for (int i = 0; i < n; i++) {
		if (97 <= *s) {
			if (*s <= 122) {
				(*s) = (*s) - 32;		//*s가 가리키는 값이 97에서 122 사이라면(a~z) 32를 빼준다(A~Z)
			}
		}
		*s++;							//*s가 가리키는 위치 증가
	}
}