#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void find_breed(char** b, int n);

int main(void) {
	int n=0;
	char* s = { 0 };
	while (1) {
		printf("10���� �ݷ��� �� ���°���� �����Ͻðڽ��ϱ�?(1 - 10 ���� �Է�, -1�� Quit) ");
		scanf("%d", &n);
		if (n == -1) {																				// n�� -1�̸� ����
			break;
		}
		find_breed(&s, n);																			// ���õ� �� ã��
		printf("���õ� �ݷ��� ��: %s\n", s);														// ���õ� �� ���
	}
}

void find_breed(char** b, int n) {
	char* dog_breeds[SIZE] = { "Russell Terrier", "Shiba Inu", "Bedlington Terrier",				// dog_breeds �ʱ�ȭ
								"German Spitz", "Yorkshire Terrier", "Pembroke Welsh Corgi",
								"Maltese", "Pomeranian", "Poodle", "Italian Greyhound" };
	*b = dog_breeds[n-1];																			// �ּҴ� 0���� �����ϱ� ������ -1
}