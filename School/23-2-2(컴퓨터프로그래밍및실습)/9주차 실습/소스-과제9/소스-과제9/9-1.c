#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct point {						// ����ü ����
	int x;
	int y;
};
typedef struct point POINT;			// ����ü ����

POINT p1, p2;						// �ΰ��� �� ����

int main(void) {
	printf("ù��° ���� ��ǥ�� �Է��Ͻÿ�(��: 3 7): ");
	scanf("%d %d", &p1.x, &p1.y);								// ù��° ���� x��ǥ, y��ǥ �Է�
	printf("�ι�° ���� ��ǥ�� �Է��Ͻÿ�(��: 3 7): ");
	scanf("%d %d", &p2.x, &p2.y);								// �ι�° ���� x��ǥ, y��ǥ �Է�
	if (p1.x == p2.x && p1.y == p2.y) {
		printf("(%d,%d)�� (%d,%d)�� ���� ���Դϴ�.", p1.x, p1.y, p2.x, p2.y);				// ������ x��ǥ�� y��ǥ�� ������ ���ٰ� ���
	}
	else {
		printf("(%d,%d)�� (%d,%d)�� ���� ���� �ƴմϴ�.", p1.x, p1.y, p2.x, p2.y);			// ������ x��ǥ�� y��ǥ�� �ٸ��� �ٸ��ٰ� ���
	}
}