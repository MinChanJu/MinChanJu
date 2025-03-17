#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void write_files(FILE* fp1, FILE* fp2, int n);
void print_files(FILE* fp1, FILE* fp2, int n);

int main() {
    FILE* fp1, * fp2;
    char fname1[100], fname2[100];

    // ���ϸ� �Է� �ޱ�
    printf("ù��° ����: ");
    scanf("%s", fname1);

    printf("�ι�° ����: ");
    scanf("%s", fname2);

    // ���� ����
    if ((fp1 = fopen(fname1, "w")) == NULL) {
        printf("���� %s�� �� �� �����ϴ�.\n", fname1);
        return 1;
    }

    if ((fp2 = fopen(fname2, "wb")) == NULL) {
        printf("���� %s�� �� �� �����ϴ�.\n", fname2);
        fclose(fp1);
        return 1;
    }

    // ���Ͽ� ���� ���� ����
    write_files(fp1, fp2, SIZE);

    // ���� �ݱ�
    fclose(fp1);
    fclose(fp2);

    // ���� �о���� ũ�� ����ϱ�
    if ((fp1 = fopen(fname1, "r")) == NULL) {
        printf("���� %s�� �� �� �����ϴ�.\n", fname1);
        return 1;
    }

    if ((fp2 = fopen(fname2, "rb")) == NULL) {
        printf("���� %s�� �� �� �����ϴ�.\n", fname2);
        fclose(fp1);
        return 1;
    }

    // ���Ͽ��� �о���� ũ�� ����ϱ�
    print_files(fp1, fp2, SIZE);

    // ���� ũ�� ���
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    printf("\n### ���� ũ�� �� ###\n");
    printf("The size of %s: %ld\n", fname1, ftell(fp1));
    printf("The size of %s: %ld\n", fname2, ftell(fp2));

    // ���� �ݱ�
    fclose(fp1);
    fclose(fp2);

    return 0;
}

void write_files(FILE* fp1, FILE* fp2, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; ++i) {
        int num = rand();
        fprintf(fp1, "%d ", num);
        fwrite(&num, sizeof(int), 1, fp2);
    }
}

void print_files(FILE* fp1, FILE* fp2, int n) {
    int value;

    // �ؽ�Ʈ ���� ��� ���
    printf("\n### �ؽ�Ʈ ���� ��� ###\n");

    for (int i = 0; i < n; ++i) {
        fscanf(fp1, "%d", &value);
        printf("%d ", value);
    }

    // ���� ���� ��� ���
    printf("\n\n### ���� ���� ��� ###\n");

    for (int i = 0; i < n; ++i) {
        fread(&value, sizeof(int), 1, fp2);
        printf("%d ", value);
    }

    printf("\n");
}
