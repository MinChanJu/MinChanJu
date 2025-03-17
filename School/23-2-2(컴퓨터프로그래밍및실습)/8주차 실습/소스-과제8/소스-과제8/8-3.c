#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

void replace_string(char source[], char find[], char replace[], char target[]);

int main(void) {
	char source[SIZE]="";
	char find[SIZE]="";
	char replace[SIZE]="";
	char target[SIZE] = "";

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(source, SIZE);									//source �迭�� ������ get_s�Լ��� �̿��Ͽ� ����
	printf("ã�� �ܾ�: ");
	scanf("%s", &find);										//ã�� �ܾ� find �迭�� ����
	printf("�ٲ� �ܾ�: ");
	scanf("%s", &replace);									//�ٲ� �ܾ� replace �迭�� ����
	replace_string(source, find, replace, target);			//source �迭���� find�� replace�� ��ȯ�Ͽ� target �迭�� ����
	printf("��ȯ�� ���ڿ�: ");
	puts(target);											//target �迭�� ���
}

void replace_string(char source[], char find[], char replace[], char target[]) {
	char seps[] = "  ,";									//�и��� ����
	char* token = 0;
	token = strtok(source, seps);							//token �и�
	while (token != NULL) {
		if (strcmp(token,find)==0) {
			strcat(target, replace);						//token�� find�̸� replace�� ��ȯ�Ͽ� ����
		}
		else {
			strcat(target, token);							//�׷��� ������ token ����
		}
		token = strtok(NULL, seps);							//���� token �и�
		strcat(target, " ");								//���� �߰�
	}
}