#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

void make_upper_str(char* s, int n);

int main(void) {
	char str[SIZE];
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, SIZE);					//str �迭�� ������ get_s�Լ��� �̿��Ͽ� ����
	make_upper_str(str, SIZE);			//str �迭�� �ҹ��ڸ� ��� �빮�ڷ� ��ȯ�ϴ� �Լ�
	printf("��ȯ�� ���ڿ�: ");
	puts(str);							//����� str �迭�� ���
}

void make_upper_str(char *s, int n) {
	for (int i = 0; i < n; i++) {
		if (97 <= *s) {
			if (*s <= 122) {
				(*s) = (*s) - 32;		//*s�� ����Ű�� ���� 97���� 122 ���̶��(a~z) 32�� ���ش�(A~Z)
			}
		}
		*s++;							//*s�� ����Ű�� ��ġ ����
	}
}