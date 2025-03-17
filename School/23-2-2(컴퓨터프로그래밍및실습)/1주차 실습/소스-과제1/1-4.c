#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double x;
    printf("실수를 입략하세요 : ");
    scanf("%lf", &x);
    printf("섭씨 온도는 %f입니다.", 3*x*x*x-7*x+10);
    return 0;
}