#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double x;
    printf("�Ǽ��� �Է��ϼ��� : ");
    scanf("%lf", &x);
    printf("���� �µ��� %f�Դϴ�.", 3*x*x*x-7*x+10);
    return 0;
}