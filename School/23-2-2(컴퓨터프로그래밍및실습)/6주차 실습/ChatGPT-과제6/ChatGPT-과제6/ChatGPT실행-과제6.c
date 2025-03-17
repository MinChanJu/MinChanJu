#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 프로토타입
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

// 함수 정의
void show_binary(int n) {
    int binary[32];
    int i = 0;

    // 10진수를 2진수로 변환하여 배열에 저장
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // 역순으로 배열을 출력하여 2진수를 표시
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}
