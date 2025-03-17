#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x, y, z;
    printf("3개의 정수를 입력하시오: ");
    scanf("%d %d %d", &x, &y, &z);
    if (x > y) {
        if (z >  y) {
            printf("최소값은 %d입니다.", y);
        }
        else {
            printf("최소값은 %d입니다.", z);
        }
    }
    else {
        if (z > x) {
            printf("최소값은 %d입니다.", x);
        }
        else {
            printf("최소값은 %d입니다.", z);
        }
    }
    return 0;
}