#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There are no prime numbers in the specified range.\n");
        return 0;
    }

    printf("Prime numbers between 2 and %d are: ", n);

    // 2�� �Ҽ��̹Ƿ� ���� ���
    printf("2 ");

    for (i = 3; i <= n; i++) {
        // i�� ¦���� ���� �Ҽ��� �� �����Ƿ� �ǳʶٱ�
        if (i % 2 == 0)
            continue;

        // i�� �Ҽ����� �˻�
        int is_prime = 1; // ó������ ��� �Ҽ��� ����
        for (j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                is_prime = 0; // �Ҽ��� �ƴϸ� �÷��׸� 0���� ����
                break;
            }
        }

        // i�� �Ҽ��� ��� ���
        if (is_prime)
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}
