#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a,b,c;
    printf("3���� ������ �Է��Ͻÿ�: ");
    scanf("%d %d %d", &a,&b,&c);
    (a >= b) ? a = b : a;
    (a >= c) ? a = c : a;
    printf("�ּҰ�: %d\n", a);
    return 0;
}