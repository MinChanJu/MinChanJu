#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char a, b, c, d;
    unsigned int x=0;
    printf("첫번째 문자를 입력하시오: ");
    scanf(" %c", &a);
    printf("두번째 문자를 입력하시오: ");
    scanf(" %c", &b);
    printf("세번째 문자를 입력하시오: ");
    scanf(" %c", &c);
    printf("네번째 문자를 입력하시오: ");
    scanf(" %c", &d);
    x = x | a;
    x = x << 8;
    x = x | b;
    x = x << 8;
    x = x | c;
    x = x << 8;
    x = x | d;
    printf("결과 값(16진수): %#X", x);
    return 0;
}