#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char a, b, c, d;
    unsigned int x=0;
    printf("ù��° ���ڸ� �Է��Ͻÿ�: ");
    scanf(" %c", &a);
    printf("�ι�° ���ڸ� �Է��Ͻÿ�: ");
    scanf(" %c", &b);
    printf("����° ���ڸ� �Է��Ͻÿ�: ");
    scanf(" %c", &c);
    printf("�׹�° ���ڸ� �Է��Ͻÿ�: ");
    scanf(" %c", &d);
    x = x | a;
    x = x << 8;
    x = x | b;
    x = x << 8;
    x = x | c;
    x = x << 8;
    x = x | d;
    printf("��� ��(16����): %#X", x);
    return 0;
}