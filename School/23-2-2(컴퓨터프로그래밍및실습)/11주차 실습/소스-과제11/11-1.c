#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10
#define INIT_ARRAY(array,size,value) for (int i=0;i<size;i++) array[i] = value+i;			// value�� �迭�� �ʱ�ȭ�ϴ� ��ũ�� ����

int main(void) {
	int a[SIZE];
	int value;
	printf("�迭 �ʱ�ȭ�� ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &value);
	INIT_ARRAY(a, SIZE, value);												// �Է¹��� value�� �迭�� �ʱ�ȭ
	printf("�ʱ�ȭ�� �迭 a = [%d", a[0]);
	for (int i = 1; i < SIZE; i++) printf(", %d", a[i]);					// �迭 ���
	printf("]");
}