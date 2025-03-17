#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>

void get_numbers(int* numbers, int n);							// �Լ� ����
void print_numbers(int* numbers, int n);						// �Լ� ����

int main(void) {
	int count;
	int* numbers;
	printf("������ ����: ");
	scanf("%d", &count);										// ������ ���� �Է�
	numbers = (int*)malloc(count * sizeof(int));				// count��ŭ ���� �޸� �Ҵ�
	if (numbers == null) {
		printf("���� �޸� �Ҵ� ����");						// ���� �޼��� ���
		exit(1);
	}

	get_numbers(numbers, count);								// get_numbers�Լ� ����
	print_numbers(numbers, count);								// print_numbers�Լ� ����
	free(numbers);												// �Ҵ�� �޸� ��ȯ
	return 0;
}

void get_numbers(int* numbers, int n) {
	for (int i = 0; i < n; i++) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &numbers[i]);								// n�� ��ŭ ���� �Է�
	}
}

void print_numbers(int* numbers, int n) {
	int sum = 0;
	printf("### �Էµ� ����: ");
	for (int i = 0; i < n; i++) {
		printf("%d ",numbers[i]);								// �Էµ� ���� ���
		sum += numbers[i];										// ��¸��� ��µǴ� ������ sum ������ ����
	}
	printf("\n### �Էµ� �������� ��: %d", sum);				// �Էµ� �������� �� sum ���
}