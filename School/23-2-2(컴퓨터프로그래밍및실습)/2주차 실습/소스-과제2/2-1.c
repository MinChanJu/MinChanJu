#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double x;
    printf("실수를 입력하시오: ");
    scanf("%lf", &x);
    printf("실수 형식: %f\n", x);
    printf("지수 형식: %e", x);
    return 0;
}