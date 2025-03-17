#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int base, int powerRaised);

int main(void)
{
    int base, powerRaised;
    printf("¹Ø¼ö: ");
    scanf("%d", &base);
    printf("Áö¼ö: ");
    scanf("%d", &powerRaised);
    printf("%d^%d = %d", base, powerRaised, power(base, powerRaised));
    return 0;
}

int power(int base, int powerRaised) {
    if (powerRaised == 0) return 1;
    return base * power(base, powerRaised - 1);
}