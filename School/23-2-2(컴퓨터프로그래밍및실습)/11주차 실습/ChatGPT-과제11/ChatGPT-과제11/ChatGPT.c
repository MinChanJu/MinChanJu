#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2개의 정수 중 최대값을 구하는 매크로 MAX(x, y)
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// 3개의 정수 중 최대값을 구하는 매크로 GET_MAX(x, y, z)
#define GET_MAX(x, y, z) MAX(MAX(x, y), z)

int main() {
    int x, y, z;

    // 사용자로부터 3개의 정수 입력 받기
    printf("3개의 정수를 입력하시오: ");
    scanf("%d %d %d", &x, &y, &z);

    // 매크로 GET_MAX를 이용하여 최대값 출력
    printf("정수 (%d, %d, %d) 중 최대값은 %d입니다.\n", x, y, z, GET_MAX(x, y, z));

    return 0;
}