#include <iostream>

int main() {
    // ����ڷκ��� ���������� ���� �Է¹ޱ�
    double earthMass;
    std::cout << "���������� ������ �Է��ϼ��� (kg): ";
    std::cin >> earthMass;

    // �޿����� ���� ��� (�޿����� �߷��� ������ �� 1/6)
    double moonMass = earthMass * (1.0 / 6.0);

    // ���� �޿����� ���� ���
    std::cout << "�޿����� ������ " << moonMass << " kg �Դϴ�." << std::endl;

    return 0;
}
