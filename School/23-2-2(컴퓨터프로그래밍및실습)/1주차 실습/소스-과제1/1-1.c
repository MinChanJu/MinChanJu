#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double m;
    printf("mile�� �Է��Ͻÿ�: ");
    scanf("%lf", &m);
    printf("%lf mile�� %lf km�Դϴ�.", m, m * 1.60934);
    return 0;
}