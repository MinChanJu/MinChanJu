#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("1,000보다 작은 정수를 입력하시오: ");
    scanf("%d", &x);
    printf("1의 자리: %d\n", x % 10);
    printf("10의 자리: %d\n",x/10%10);
    printf("100의 자리: %d\n",x/100);
    return 0;
}