#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    float m;
    printf("화씨 온도를 입략하시오 : ");
    scanf("%f", &m);
    printf("섭씨 온도는 %f입니다.", (m - 32) * 5 / 9);
    return 0;
}