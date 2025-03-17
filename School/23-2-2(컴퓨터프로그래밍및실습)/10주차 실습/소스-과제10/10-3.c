#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

struct product {
    char pid[20];
    double price;
    double number;
};

void find_total(FILE* fp, int n);

int main(void) {
    FILE* fp;
    char fname[100];
    printf("���ϸ��� �Է��ϼ���: ");
    scanf("%s", fname);

    fp = fopen(fname, "rb");                                                                         // ���� ����

    if (fp == NULL) {
        printf("���� %s�� �� �� �����ϴ�.\n", fname);                                                // ������ ������ ���ϸ� �޼��� ���
    }

    find_total(fp, SIZE);                                                                            // ���� �б�
    fclose(fp);                                                                                      // ���� �ݱ�

    return 0;
}

void find_total(FILE* fp, int n) {
    struct product p[SIZE];
    double total = 0.0;

    printf("### ��ǰ �Ǹ� ������ ###\n");                                                             // ��� ���
    for (int i = 0; i < n; ++i) {
        fread(&p[i], sizeof(struct product), 1, fp);
        printf("pid = %s, price = %.2f, number = %.0f\n", p[i].pid, p[i].price, p[i].number);         // �̸�,����,���� ���
        total += p[i].price * p[i].number;                                                            // total�� ���� ���ϱ� ���� ���ϱ�
    }
    printf("�Ǹ� �Ѿ�: %.2f", total);                                                                 // total ���
}