#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double m;
    printf("mile을 입략하시오: ");
    scanf("%lf", &m);
    printf("%lf mile은 %lf km입니다.", m, m * 1.60934);
    return 0;
}