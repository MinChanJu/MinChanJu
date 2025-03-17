#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct cont {													// ����ü ����
	char name[100];
	char email[100];
}CONTACT;

void get_contacts(CONTACT* conts, int n);								// �Լ� ����
void print_strings(CONTACT* conts, int n);								// �Լ� ����

int main(void) {
	CONTACT* conts;
	int n;
	printf("�ּ��� ����: ");
	scanf("%d", &n);													// �ּ��� ���� �Է�
	conts = (CONTACT*)malloc(n * sizeof(CONTACT));						// n��ŭ ���� �޸� �Ҵ�
	if (conts == NULL) {
		printf("���� �޸� �Ҵ� ����");								// ���� �޼��� ���
		exit(1);
	}
	get_contacts(conts, n);												// get_contacts �Լ� ����
	print_strings(conts, n);											// print_strings �Լ� ����
	free(conts);														// �޸� ��ȯ
	return 0;
}

void get_contacts(CONTACT* conts, int n) {
	for (int i = 0; i < n; i++) {
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", conts[i].name);										// �̸� �Է�
		printf("�̸����� �Է��Ͻÿ�: ");
		scanf("%s", conts[i].email);									// �̸��� �Է�
	}
}

void print_strings(CONTACT* conts, int n) {
	printf("==============================================\n");
	printf("�̸�\t\t�̸���\n");											// ��� ���
	printf("==============================================\n");
	for (int i = 0; i < n; i++) {
		printf("%s\t\t%s\n", conts[i].name, conts[i].email);			// �� �̸� �̸��� ���
	}
	printf("==============================================");
}