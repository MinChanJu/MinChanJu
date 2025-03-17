#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float x, y;

    printf("Enter the x and y coordinates of the point separated by a space: ");
    scanf("%f %f", &x, &y);

    if (x == 0 && y == 0) {
        printf("The point is at the origin.\n");
    }
    else if (x == 0) {
        printf("The point is on the %s y-axis.\n", (y > 0) ? "positive" : "negative");
    }
    else if (y == 0) {
        printf("The point is on the %s x-axis.\n", (x > 0) ? "positive" : "negative");
    }
    else {
        if (x > 0) {
            if (y > 0) {
                printf("The point is in quadrant 1.\n");
            }
            else {
                printf("The point is in quadrant 4.\n");
            }
        }
        else {
            if (y > 0) {
                printf("The point is in quadrant 2.\n");
            }
            else {
                printf("The point is in quadrant 3.\n");
            }
        }
    }

    return 0;
}