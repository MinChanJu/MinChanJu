#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

void replace_space(char s[], int n);

int main(void) {
	char str[SIZE];
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, SIZE);					//str �迭�� ������ get_s�Լ��� �̿��Ͽ� ����
	replace_space(str, SIZE);			//str �迭�� ������ /�� ��ȯ�ϴ� �Լ�
	printf("������ ����� ���ڿ�: ");
	puts(str);							//����� str �迭�� ���
}

void replace_space(char s[], int n) {
	char tmp[SIZE];
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			tmp[i] = '/';				//s[i]�� ������ ��� /�� ��ȯ
		}
		else {
			tmp[i] = s[i];				//�� �ܿ� ��� �״�� ����
		}
	}
	strcpy(s, tmp);						//s�� tmp�� ����
}