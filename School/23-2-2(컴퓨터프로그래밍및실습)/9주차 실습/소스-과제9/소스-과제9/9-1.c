#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct point {						// 구조체 생성
	int x;
	int y;
};
typedef struct point POINT;			// 구조체 정의

POINT p1, p2;						// 두개의 점 선언

int main(void) {
	printf("첫번째 점의 좌표를 입력하시오(예: 3 7): ");
	scanf("%d %d", &p1.x, &p1.y);								// 첫번째 점의 x좌표, y좌표 입력
	printf("두번째 점의 좌표를 입력하시오(예: 3 7): ");
	scanf("%d %d", &p2.x, &p2.y);								// 두번째 점의 x좌표, y좌표 입력
	if (p1.x == p2.x && p1.y == p2.y) {
		printf("(%d,%d)와 (%d,%d)은 같은 점입니다.", p1.x, p1.y, p2.x, p2.y);				// 두점의 x좌표와 y좌표가 같을시 같다고 출력
	}
	else {
		printf("(%d,%d)와 (%d,%d)은 같은 점이 아닙니다.", p1.x, p1.y, p2.x, p2.y);			// 두점의 x좌표와 y좌표가 다를시 다르다고 출력
	}
}