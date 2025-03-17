#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x,sum=0,k=1;
    printf("양의 정수를 입력하시오: ");
    scanf("%d", &x);
    while (sum < x) {
        sum += k;
        k += 1;
    }
    sum -= k-1;
    k -= 2;
    printf("1부터 %d까지의 합이 %d입니다.", k, sum);
    return 0;
}