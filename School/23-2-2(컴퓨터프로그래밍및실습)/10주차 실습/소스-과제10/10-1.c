#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_file(FILE* fp);
void convert_to_upper(FILE* fp1, FILE* fp2);

int main(void) {
	FILE* fp1, * fp2;
	char fname1[100], fname2[100];
	printf("ù��° ����: ");
	scanf("%s", &fname1);
	printf("�ι�° ����: ");
	scanf("%s", &fname2);
	fp1 = fopen(fname1, "r");										// ���� ����
	if (fp1 == NULL) {
		printf("���� %s�� �� �� �����ϴ�.\n", fname1);				// ������ ���� �޼��� ���
	}
	fp2 = fopen(fname2, "w+");										// ���� ����
	if (fp2 == NULL) {
		printf("���� %s�� �� �� �����ϴ�.\n", fname2);				// ������ ���� �޼��� ���
	}
	printf("### ���� ���� ###\n");
	print_file(fp1);												// ���� ���� ���
	fseek(fp1, 0, SEEK_SET);										// ������ ��ġ ����

	convert_to_upper(fp1, fp2);										// ���� ��ȯ

	printf("\n### ��ȯ�� ���� ###\n");
	fseek(fp2, 0, SEEK_SET);										// ������ ��ġ ����
	print_file(fp2);												// ��ȯ�� ���� ���

	fclose(fp1);													// ���� �ݱ�
	fclose(fp2);													// ���� �ݱ�

	return 0;
}

void print_file(FILE* fp) {
	char buffer[256];
	while (fgets(buffer, 256, fp) != NULL) {
		printf("%s",buffer);										// ���� �а� ���
	}
}

void convert_to_upper(FILE* fp1, FILE* fp2) {
	int a;
	while ((a = fgetc(fp1)) != EOF) {
		if (a > 90) {												// �ҹ��ڸ� 32�� ���� �빮�ڷ� �ٲ� �� ���
			fprintf(fp2, "%c", a - 32);
		}
		else {
			fprintf(fp2, "%c", a);
		}
	}
}