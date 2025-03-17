#include <iostream>

int main() {
    // 사용자로부터 지구에서의 질량 입력받기
    double earthMass;
    std::cout << "지구에서의 질량을 입력하세요 (kg): ";
    std::cin >> earthMass;

    // 달에서의 질량 계산 (달에서의 중력은 지구의 약 1/6)
    double moonMass = earthMass * (1.0 / 6.0);

    // 계산된 달에서의 질량 출력
    std::cout << "달에서의 질량은 " << moonMass << " kg 입니다." << std::endl;

    return 0;
}
