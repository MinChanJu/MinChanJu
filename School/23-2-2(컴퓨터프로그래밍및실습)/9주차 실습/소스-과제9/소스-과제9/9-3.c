#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void find_breed(char** b, int n);

int main(void) {
	int n=0;
	char* s = { 0 };
	while (1) {
		printf("10종의 반려견 중 몇번째종을 선택하시겠습니까?(1 - 10 사이 입력, -1은 Quit) ");
		scanf("%d", &n);
		if (n == -1) {																				// n이 -1이면 중지
			break;
		}
		find_breed(&s, n);																			// 선택된 종 찾기
		printf("선택된 반려견 종: %s\n", s);														// 선택된 종 출력
	}
}

void find_breed(char** b, int n) {
	char* dog_breeds[SIZE] = { "Russell Terrier", "Shiba Inu", "Bedlington Terrier",				// dog_breeds 초기화
								"German Spitz", "Yorkshire Terrier", "Pembroke Welsh Corgi",
								"Maltese", "Pomeranian", "Poodle", "Italian Greyhound" };
	*b = dog_breeds[n-1];																			// 주소는 0부터 시작하기 때문에 -1
}