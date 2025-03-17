#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double earth_mass, moon_mass;

    printf("지구에서의 질량을 kg 단위로 입력하세요: ");
    scanf("%lf", &earth_mass);

    // 달에서의 질량은 지구에서의 질량의 1/6입니다.
    moon_mass = earth_mass / 6.0;

    printf("달에서의 질량은 %.2lf kg 입니다.\n", moon_mass);

    return 0;
}
