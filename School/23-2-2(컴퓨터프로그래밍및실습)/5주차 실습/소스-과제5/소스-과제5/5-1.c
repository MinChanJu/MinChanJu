#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double r_rand(void);

int main(void)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++) {
        printf("%lf, ", r_rand());
    }
    printf("%lf", r_rand());
    return 0;
}

double r_rand(void)
{
    double i;
    i = rand();
    return i / RAND_MAX+1;
}