#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double height, weight, sweight;
    printf("Ű�� ü���� �Է��Ͻÿ�: ");
    scanf("%lf %lf", &height, &weight);
    sweight = (height - 100) * 9/10;
    if (sweight > weight) {
        printf("��ü���Դϴ�.");
    }
    else if (sweight < weight) {
        printf("��ü���Դϴ�.");
    }
    else {
        printf("ǥ��ü���Դϴ�.");
    }
    return 0;
}