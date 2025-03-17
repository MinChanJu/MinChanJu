#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("양의 정수를 입력하시오: ");
    scanf("%d", &x);
    printf("\"%d\"의 2의 보수(16진수): %#x\n", x,~x+1);
    return 0;
}