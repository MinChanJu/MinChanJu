#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;
    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &x);
    printf("\"%d\"�� 2�� ����(16����): %#x\n", x,~x+1);
    return 0;
}