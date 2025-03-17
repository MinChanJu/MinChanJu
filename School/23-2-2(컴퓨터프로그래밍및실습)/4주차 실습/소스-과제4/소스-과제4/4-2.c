#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double height, weight, sweight;
    printf("키와 체중을 입력하시오: ");
    scanf("%lf %lf", &height, &weight);
    sweight = (height - 100) * 9/10;
    if (sweight > weight) {
        printf("저체중입니다.");
    }
    else if (sweight < weight) {
        printf("과체중입니다.");
    }
    else {
        printf("표준체중입니다.");
    }
    return 0;
}