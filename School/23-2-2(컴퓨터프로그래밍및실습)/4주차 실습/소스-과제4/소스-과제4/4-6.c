#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("양의 정수를 입력하시오: ");
    scanf("%d", &x);
    do {
        printf("%d",x % 10);
        x /= 10;
    } while (x != 0);
    return 0;
}