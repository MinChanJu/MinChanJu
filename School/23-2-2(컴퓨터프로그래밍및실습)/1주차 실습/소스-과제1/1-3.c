#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    float m;
    printf("ȭ�� �µ��� �Է��Ͻÿ� : ");
    scanf("%f", &m);
    printf("���� �µ��� %f�Դϴ�.", (m - 32) * 5 / 9);
    return 0;
}