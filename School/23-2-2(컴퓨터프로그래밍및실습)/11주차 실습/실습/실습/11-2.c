#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define GET_BIT(n,pos)	(((n) >> (pos)) & 0x01)								// n�� pos��° ��Ʈ�� ��ȯ�ϴ� ��ũ��
#define SET_BIT(n,pos)	((n) |= (0x01 << (pos)))							// n�� pos��° ��Ʈ�� 1�� �ٲٴ� ��ũ��
#define CLR_BIT(n,pos)	((n) &= ~(0x01 << (pos)))							// n�� pos��° ��Ʈ�� 0���� �ٲٴ� ��ũ��

int main(void) {
	int n = 0x00000e05;																	// n�� �ʱⰪ ����
	printf("n = %#010X\n", n);															// n ���
	int pos;
	printf("n���� Ȯ���� ��Ʈ�� ��ġ�� �Է��Ͻÿ�(0 - 31���� �Է�): ");
	scanf("%d", &pos);
	printf("GET_BIT(n,%d)�� ���: %d\n", pos, GET_BIT(n, pos));							// n�� pos��° ��Ʈ ���
	printf("n���� 1�� ������ ��Ʈ�� ��ġ�� �Է��Ͻÿ�(0 - 31���� �Է�): ");
	scanf("%d", &pos);
	SET_BIT(n, pos);																	// n�� pos��° ��Ʈ�� 1�� ��ȯ
	printf("SET_BIT(n,%d)�� ���: %#010X\n", pos, n);									// n ���
	printf("n���� 0�� ������ ��Ʈ�� ��ġ�� �Է��Ͻÿ�(0 - 31���� �Է�): ");
	scanf("%d", &pos);
	CLR_BIT(n, pos);																	// n�� pos��° ��Ʈ�� 0���� ��ȯ
	printf("CLR_BIT(n,%d)�� ���: %#010X", pos, n);										// n ���
	return 0;
}