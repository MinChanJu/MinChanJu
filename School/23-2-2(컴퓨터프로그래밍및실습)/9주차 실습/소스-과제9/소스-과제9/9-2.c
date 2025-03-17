#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

void get_shape_data(struct shape s[], int n);
void print_shape_data(struct shape s[], int n);

enum shape_type { TRIANGLE, RECTANGLE, CIRCLE };			// 열거형 정의 

struct shape {												// 구조체 정의
	int type;
	union {
		struct tri {
			double base, height;
		};
		struct rect {
			double width, height2;							// 변수명이 똑같아 오류가 나 height2로 선언
		};
		struct circ {
			double radius;
		};
	}p;
};

int main(void) {
	struct shape s[SIZE];
	printf("### 도형 데이터 입력 ###\n");
	get_shape_data(s, SIZE);								// SIZE만큼 도형들 입력받음
	printf("\n### 도형 데이터 출력 ###\n");
	print_shape_data(s, SIZE);								// 도형의 면적 출력
}

void get_shape_data(struct shape s[], int n) {
	enum shape_type st;
	for (int i = 0; i < n; i++) {
		printf("도형의 타입을 입력하시오(0-TRIANGLE, 1-RECTANGLE, 2-CIRCLE): ");
		scanf("%d", &st);
		switch (st) {
			case TRIANGLE:																// 삼각형일 경우 밑변과 높이 입력
				printf("밑변과 높이를 입력하시오(예를 들어서 2 5): ");
				scanf("%lf %lf", &s[i].p.base, &s[i].p.height);
				s[i].type = st;
				break;
			case RECTANGLE:																// 사각형일 경우 가로와 세로 입력
				printf("가로와 세로의 길이를 입력하시오(예를 들어서 3 4): ");
				scanf("%lf %lf", &s[i].p.width, &s[i].p.height2);
				s[i].type = st;
				break;
			case CIRCLE:																// 원일 경우 반지름 입력
				printf("반지름을 입력하시오(예를 들어서 8): ");
				scanf("%lf", &s[i].p.radius);
				s[i].type = st;
				break;
			default:																	// 모두 아닐경우 오류 메세지 출력
				printf("도형의 타입이 잘못 선택되었습니다.\n");
				i--;
				break;
		}
	}
}

void print_shape_data(struct shape s[], int n) {
	int count=1;
	enum shape_type st;
	printf("출력할 도형의 타입을 입력하시오(0-TRIANGLE, 1-RECTANGLE, 2-CIRCLE): ");
	scanf("%d", &st);
	switch (st) {
		case TRIANGLE:																	// 삼각형일 경우 밑변 곱하기 높이 나누기 2 만약 삼각형이 없으면 "출력할 도형이 업습니다." 출력
			for (int i = 0; i < n; i++) {
				if (s[i].type == st) {
					printf("%d번째 삼각형 면적은 %lf\n", count, s[i].p.base * s[i].p.height / 2);
					count++;
				}
			}
			if (count == 1) {
				printf("출력할 도형이 없습니다.\n");
			}
			break;
		case RECTANGLE:																	// 사각형일 경우 가로 곱하기 세로 만약 사각형이 없으면 "출력할 도형이 업습니다." 출력
			for (int i = 0; i < n; i++) {
				if (s[i].type == st) {
					printf("%d번째 사각형 면적은 %lf\n", count, s[i].p.width * s[i].p.height2);
					count++;
				}
			}
			if (count == 1) {
				printf("출력할 도형이 없습니다.\n");
			}
			break;
		case CIRCLE:																	// 원일 경우 반지름 곱하기 반지름 곱하기 3.14 만약 원이 없으면 "출력할 도형이 업습니다." 출력
			for (int i = 0; i < n; i++) {
				if (s[i].type == st) {
					printf("%d번째 원 면적은 %lf\n", count, s[i].p.radius * s[i].p.radius * 3.14);
					count++;
				}
			}
			if (count == 1) {
				printf("출력할 도형이 없습니다.\n");
			}
			break;
		default:																		// 모두 아닐경우 "출력할 도형이 업습니다." 출력
			printf("출력할 도형이 없습니다.\n");
			break;
	}
}