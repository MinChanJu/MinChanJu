#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int X;
    printf("16���� ������ �Է��Ͻÿ�: ");
    scanf("%x", &X);
    printf("10����: %d\n",X);
    printf("8����: %o\n",X);
    printf("16����: %X",X);
    return 0;
}