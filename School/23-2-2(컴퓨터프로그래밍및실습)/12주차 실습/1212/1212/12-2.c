#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void get_strings(char** strings, int n);						// get_strings�Լ� ����
void print_strings(char** strings, int n);						// print_strings�Լ� ����

int main(void) {
	int n;
	char** strings;
	printf("���ڿ��� ����: ");
	scanf("%d", &n);											// ���ڿ��� ���� �Է�
	strings = (char **)malloc(n * sizeof(char*));				// n�� ��ŭ ���� �޸� �Ҵ�
	for (int i = 0; i < n; i++) {
		strings[i] = (char*)malloc(100 * sizeof(char));			// ���� 100��ŭ ���� �޸� �Ҵ�
		if (strings[i] == NULL) {
			printf("���� �޸� �Ҵ� ����");					// ���� �޼��� ���
			exit(1);
		}
	}
	get_strings(strings, n);									// get_strings�Լ� ����
	print_strings(strings, n);									// print_strings�Լ� ����
	free(strings);												// �Ҵ�� �޸� ��ȯ
	return 0;
}

void get_strings(char** strings, int n) {
	for (int i = 0; i < n; i++) {
		printf("���ڿ��� �Է��Ͻÿ�: ");
		scanf("%s", strings[i]);								// n�� ��ŭ ���ڿ� �Է�
	}
}

void print_strings(char** strings, int n) {
	printf("### �Էµ� ���ڿ�:\n{");							// ��� ���
	for (int i = 0; i < n-1; i++) {
		printf("\"%s\", ", strings[i]);							// �Էµ� ���ڿ� ���
	}
	printf("\"%s\"}", strings[n-1]);
}