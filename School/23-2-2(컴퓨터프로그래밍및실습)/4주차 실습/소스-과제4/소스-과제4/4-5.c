#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x,sum=0,k=1;
    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &x);
    while (sum < x) {
        sum += k;
        k += 1;
    }
    sum -= k-1;
    k -= 2;
    printf("1���� %d������ ���� %d�Դϴ�.", k, sum);
    return 0;
}