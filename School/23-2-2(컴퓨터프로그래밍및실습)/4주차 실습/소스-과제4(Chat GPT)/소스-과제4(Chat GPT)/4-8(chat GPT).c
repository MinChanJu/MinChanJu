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

    // 2는 소수이므로 먼저 출력
    printf("2 ");

    for (i = 3; i <= n; i++) {
        // i가 짝수인 경우는 소수일 수 없으므로 건너뛰기
        if (i % 2 == 0)
            continue;

        // i가 소수인지 검사
        int is_prime = 1; // 처음에는 모두 소수로 가정
        for (j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                is_prime = 0; // 소수가 아니면 플래그를 0으로 설정
                break;
            }
        }

        // i가 소수인 경우 출력
        if (is_prime)
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}
