#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a,b,c;
    printf("3개의 정수를 입력하시오: ");
    scanf("%d %d %d", &a,&b,&c);
    (a >= b) ? a = b : a;
    (a >= c) ? a = c : a;
    printf("최소값: %d\n", a);
    return 0;
}