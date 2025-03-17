#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void compare_files(FILE* fp1, FILE* fp2);

int main(void) {
	FILE* fp1, *	 fp2;
	char fname1[100], fname2[100];
	printf("ù��° ����: ");
	scanf("%s", &fname1);
	printf("�ι�° ����: ");
	scanf("%s", &fname2);
	fp1 = fopen(fname1, "r");										// ���� ����
	if (fp1 == NULL) {
		printf("���� %s�� �� �� �����ϴ�.\n", fname1);				// ������ ���� �޼��� ���
	}
	fp2 = fopen(fname2, "r");										// ���� ����
	if (fp2 == NULL) {
		printf("���� %s�� �� �� �����ϴ�.\n", fname2);				// ������ ���� �޼��� ���
	}
	compare_files(fp1, fp2);										// ���� ��ȯ

	fclose(fp1);													// ���� �ݱ�
	fclose(fp2);													// ���� �ݱ�
}

void compare_files(FILE* fp1, FILE* fp2) {
	char buffer1[1024];
	char buffer2[1024];
	fgets(buffer1, 1024, fp1);
	fgets(buffer2, 1024, fp2);
	while ((buffer1 != NULL) && buffer2 != NULL) {
		if (strcmp(buffer1, buffer2) != 0) {
			printf("<< %s\n", buffer1);
			printf(">> %s\n", buffer2);
		}
		fgets(buffer1, 1024, fp1);
		fgets(buffer2, 1024, fp2);
	}
}