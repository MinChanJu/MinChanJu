#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("ASCII 코드를 입력하시오: ");
    scanf("%d", &x);
    printf("입력 코드 +7에 해당되는 문자: %c", x + 7);
    return 0;
}