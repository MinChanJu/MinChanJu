#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("���ڸ� �Է��Ͻÿ�: ");
    scanf("%c", &x);
    printf("3���� ����: %c,%c,%c", x - 1, x + 2, x + 9);
    return 0;
}