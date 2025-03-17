#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x, y;

    // ����ڷκ��� x ��ǥ �Է�
    printf("Enter the x-coordinate: ");
    scanf("%d", &x);

    // ����ڷκ��� y ��ǥ �Է�
    printf("Enter the y-coordinate: ");
    scanf("%d", &y);

    // ���� �����ڸ� ����Ͽ� ��и��� �Ǵ��ϰ� ���
    if (x > 0) {
        if (y > 0) {
            printf("The point (%d, %d) is in quadrant 1.\n", x, y);
        }
        else if (y < 0) {
            printf("The point (%d, %d) is in quadrant 4.\n", x, y);
        }
        else {
            printf("The point (%d, %d) is on the positive x-axis.\n", x, y);
        }
    }
    else if (x < 0) {
        if (y > 0) {
            printf("The point (%d, %d) is in quadrant 2.\n", x, y);
        }
        else if (y < 0) {
            printf("The point (%d, %d) is in quadrant 3.\n", x, y);
        }
        else {
            printf("The point (%d, %d) is on the negative x-axis.\n", x, y);
        }
    }
    else {
        if (y != 0) {
            printf("The point (%d, %d) is on the y-axis.\n", x, y);
        }
        else {
            printf("The point (%d, %d) is at the origin.\n", x, y);
        }
    }

    return 0;
}
