#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &x);
    do {
        printf("%d",x % 10);
        x /= 10;
    } while (x != 0);
    return 0;
}