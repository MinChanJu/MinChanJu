#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("문자를 입력하시오: ");
    scanf("%c", &x);
    printf("3개의 문자: %c,%c,%c", x - 1, x + 2, x + 9);
    return 0;
}