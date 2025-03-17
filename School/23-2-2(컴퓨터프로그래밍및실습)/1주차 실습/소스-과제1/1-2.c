#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double m;
    printf("주사위 한변의 길이를 입략하시오: ");
    scanf("%lf", &m);
    printf("주사위 면적의 Rj합계는 %lf입니다.", m * m * 6);
    return 0;
}