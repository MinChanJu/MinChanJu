#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("1,000���� ���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &x);
    printf("1�� �ڸ�: %d\n", x % 10);
    printf("10�� �ڸ�: %d\n",x/10%10);
    printf("100�� �ڸ�: %d\n",x/100);
    return 0;
}