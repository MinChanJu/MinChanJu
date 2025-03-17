#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int X;
    printf("16진수 정수를 입력하시오: ");
    scanf("%x", &X);
    printf("10진수: %d\n",X);
    printf("8진수: %o\n",X);
    printf("16진수: %X",X);
    return 0;
}