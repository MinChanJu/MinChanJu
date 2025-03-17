#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

void get_shape_data(struct shape s[], int n);
void print_shape_data(struct shape s[], int n);

enum shape_type { TRIANGLE, RECTANGLE, CIRCLE };			// ������ ���� 

struct shape {												// ����ü ����
	int type;
	union {
		struct tri {
			double base, height;
		};
		struct rect {
			double width, height2;							// �������� �Ȱ��� ������ �� height2�� ����
		};
		struct circ {
			double radius;
		};
	}p;
};

int main(void) {
	struct shape s[SIZE];
	printf("### ���� ������ �Է� ###\n");
	get_shape_data(s, SIZE);								// SIZE��ŭ ������ �Է¹���
	printf("\n### ���� ������ ��� ###\n");
	print_shape_data(s, SIZE);								// ������ ���� ���
}

void get_shape_data(struct shape s[], int n) {
	enum shape_type st;
	for (int i = 0; i < n; i++) {
		printf("������ Ÿ���� �Է��Ͻÿ�(0-TRIANGLE, 1-RECTANGLE, 2-CIRCLE): ");
		scanf("%d", &st);
		switch (st) {
			case TRIANGLE:																// �ﰢ���� ��� �غ��� ���� �Է�
				printf("�غ��� ���̸� �Է��Ͻÿ�(���� �� 2 5): ");
				scanf("%lf %lf", &s[i].p.base, &s[i].p.height);
				s[i].type = st;
				break;
			case RECTANGLE:																// �簢���� ��� ���ο� ���� �Է�
				printf("���ο� ������ ���̸� �Է��Ͻÿ�(���� �� 3 4): ");
				scanf("%lf %lf", &s[i].p.width, &s[i].p.height2);
				s[i].type = st;
				break;
			case CIRCLE:																// ���� ��� ������ �Է�
				printf("�������� �Է��Ͻÿ�(���� �� 8): ");
				scanf("%lf", &s[i].p.radius);
				s[i].type = st;
				break;
			default:																	// ��� �ƴҰ�� ���� �޼��� ���
				printf("������ Ÿ���� �߸� ���õǾ����ϴ�.\n");
				i--;
				break;
		}
	}
}

void print_shape_data(struct shape s[], int n) {
	int count=1;
	enum shape_type st;
	printf("����� ������ Ÿ���� �Է��Ͻÿ�(0-TRIANGLE, 1-RECTANGLE, 2-CIRCLE): ");
	scanf("%d", &st);
	switch (st) {
		case TRIANGLE:																	// �ﰢ���� ��� �غ� ���ϱ� ���� ������ 2 ���� �ﰢ���� ������ "����� ������ �����ϴ�." ���
			for (int i = 0; i < n; i++) {
				if (s[i].type == st) {
					printf("%d��° �ﰢ�� ������ %lf\n", count, s[i].p.base * s[i].p.height / 2);
					count++;
				}
			}
			if (count == 1) {
				printf("����� ������ �����ϴ�.\n");
			}
			break;
		case RECTANGLE:																	// �簢���� ��� ���� ���ϱ� ���� ���� �簢���� ������ "����� ������ �����ϴ�." ���
			for (int i = 0; i < n; i++) {
				if (s[i].type == st) {
					printf("%d��° �簢�� ������ %lf\n", count, s[i].p.width * s[i].p.height2);
					count++;
				}
			}
			if (count == 1) {
				printf("����� ������ �����ϴ�.\n");
			}
			break;
		case CIRCLE:																	// ���� ��� ������ ���ϱ� ������ ���ϱ� 3.14 ���� ���� ������ "����� ������ �����ϴ�." ���
			for (int i = 0; i < n; i++) {
				if (s[i].type == st) {
					printf("%d��° �� ������ %lf\n", count, s[i].p.radius * s[i].p.radius * 3.14);
					count++;
				}
			}
			if (count == 1) {
				printf("����� ������ �����ϴ�.\n");
			}
			break;
		default:																		// ��� �ƴҰ�� "����� ������ �����ϴ�." ���
			printf("����� ������ �����ϴ�.\n");
			break;
	}
}