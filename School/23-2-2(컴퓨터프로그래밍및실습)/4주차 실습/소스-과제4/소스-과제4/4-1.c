#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x, y, z;
    printf("3���� ������ �Է��Ͻÿ�: ");
    scanf("%d %d %d", &x, &y, &z);
    if (x > y) {
        if (z >  y) {
            printf("�ּҰ��� %d�Դϴ�.", y);
        }
        else {
            printf("�ּҰ��� %d�Դϴ�.", z);
        }
    }
    else {
        if (z > x) {
            printf("�ּҰ��� %d�Դϴ�.", x);
        }
        else {
            printf("�ּҰ��� %d�Դϴ�.", z);
        }
    }
    return 0;
}