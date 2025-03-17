#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int i, j, k;
    for (i = 0; i <= 4; i++) {
        for (j = 1; j <= (4-i); j++) {
            printf(" ");
        }
        for (k = 1; k <= (1+i); k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}