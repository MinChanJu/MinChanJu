#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare_files(FILE* fp1, FILE* fp2);

int main(void) {
    char fname1[100], fname2[100];
    FILE* fp1, * fp2;

    printf("ù��° ����: ");
    scanf("%s", fname1);
    printf("�ι�° ����: ");
    scanf("%s", fname2);
    fp1 = fopen(fname1, "r");                                                 // ���� ����
    if (fp1 == NULL) {
        printf("���� %s��(��) �� �� �����ϴ�.\n", fname1);                    // ������ ���� ���ϸ� �޼��� ���
    }

    fp2 = fopen(fname2, "r");                                                 // ���� ����
    if (fp2 == NULL) {
        printf("���� %s��(��) �� �� �����ϴ�.\n", fname2);                    // ������ ���� ���ϸ� �޼��� ���
    }

    compare_files(fp1, fp2);                                                  // �� ���� ��

    fclose(fp1);                                                              // ���� �ݱ�
    fclose(fp2);                                                              // ���� �ݱ�

    return 0;
}

void compare_files(FILE* fp1, FILE* fp2) {
    char buffer1[1024], buffer2[1024];
    char* bu1, * bu2;
    while (1) {
        bu1 = fgets(buffer1, sizeof(buffer1), fp1);
        bu2 = fgets(buffer2, sizeof(buffer2), fp2);
        if (bu1 == NULL || bu2 == NULL) {                                     // �� ���� �� �ϳ��� ������ ����
            break;
        }
        if (strcmp(buffer1, buffer2) != 0) {                                  // �� ���� �� �� �ٸ��� ���
            printf("<< %s", buffer1);
            printf("\n>> %s", buffer2);
        }
    }
}