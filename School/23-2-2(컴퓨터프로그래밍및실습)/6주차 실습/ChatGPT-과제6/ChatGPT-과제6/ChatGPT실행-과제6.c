#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ� ������Ÿ��
void show_binary(int n);

int main() {
    int decimalNumber;

    while (1) {
        printf("Enter a decimal number (-1 to quit): ");
        scanf("%d", &decimalNumber);

        if (decimalNumber == -1) {
            break;
        }

        printf("Binary equivalent: ");
        show_binary(decimalNumber);
        printf("\n");
    }

    return 0;
}

// �Լ� ����
void show_binary(int n) {
    int binary[32];
    int i = 0;

    // 10������ 2������ ��ȯ�Ͽ� �迭�� ����
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // �������� �迭�� ����Ͽ� 2������ ǥ��
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}
