#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define GET_BIT(n,pos)	(((n) >> (pos)) & 0x01)								// n�� pos��° ��Ʈ�� ��ȯ�ϴ� ��ũ��

void print_bits(int value);

int main(void) {
	int n, k, pos, val;
	printf("�������� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	while (1) {
		printf("���� �̵��� 0, ������ �̵��� 1�� �Է��Ͻÿ�(-1�� Quit) : ");
		scanf("%d", &k);
		if (k == -1) break;															// �Է��� -1�̸� ����
		printf("�̵���ų ��Ʈ ���� �Է��Ͻÿ�:");
		scanf("%d", &pos);
		printf("�̵� ��: ");
		print_bits(n);																// n�� ��Ʈ ���
		if (k == 0) {
			for (int i = 0; i < pos; i++) n = n * 2;								// ���� �̵��� ��� 2�� pos�� ����
		}
		else if (k == 1) {
			for (int i = 0; i < pos; i++) n = n / 2;								// ������ �̵��� ��� 2�� pos�� ����
		}
		printf("�̵� ��: ");
		print_bits(n);																// n�� ��Ʈ ���
	}
}

void print_bits(int value) {
	for (int i = 31; i >= 0; i--) {
		if ((i + 1) % 4 == 0) printf(" %d", GET_BIT(value, i));						// 4ĭ���� ���� �ϰ� ���
		else printf("%d", GET_BIT(value, i));
	}
	printf("\n");
}