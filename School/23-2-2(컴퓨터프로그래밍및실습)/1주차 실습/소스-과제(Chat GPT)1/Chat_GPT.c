#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double earth_mass, moon_mass;

    printf("���������� ������ kg ������ �Է��ϼ���: ");
    scanf("%lf", &earth_mass);

    // �޿����� ������ ���������� ������ 1/6�Դϴ�.
    moon_mass = earth_mass / 6.0;

    printf("�޿����� ������ %.2lf kg �Դϴ�.\n", moon_mass);

    return 0;
}
