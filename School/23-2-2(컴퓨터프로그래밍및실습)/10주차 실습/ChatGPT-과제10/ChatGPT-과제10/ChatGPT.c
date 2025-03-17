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

    // 파일명 입력 받기
    printf("첫번째 파일: ");
    scanf("%s", fname1);

    printf("두번째 파일: ");
    scanf("%s", fname2);

    // 파일 열기
    if ((fp1 = fopen(fname1, "w")) == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname1);
        return 1;
    }

    if ((fp2 = fopen(fname2, "wb")) == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname2);
        fclose(fp1);
        return 1;
    }

    // 파일에 랜덤 정수 쓰기
    write_files(fp1, fp2, SIZE);

    // 파일 닫기
    fclose(fp1);
    fclose(fp2);

    // 파일 읽어오고 크기 출력하기
    if ((fp1 = fopen(fname1, "r")) == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname1);
        return 1;
    }

    if ((fp2 = fopen(fname2, "rb")) == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname2);
        fclose(fp1);
        return 1;
    }

    // 파일에서 읽어오고 크기 출력하기
    print_files(fp1, fp2, SIZE);

    // 파일 크기 출력
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    printf("\n### 파일 크기 비교 ###\n");
    printf("The size of %s: %ld\n", fname1, ftell(fp1));
    printf("The size of %s: %ld\n", fname2, ftell(fp2));

    // 파일 닫기
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

    // 텍스트 파일 출력 헤더
    printf("\n### 텍스트 파일 출력 ###\n");

    for (int i = 0; i < n; ++i) {
        fscanf(fp1, "%d", &value);
        printf("%d ", value);
    }

    // 이진 파일 출력 헤더
    printf("\n\n### 이진 파일 출력 ###\n");

    for (int i = 0; i < n; ++i) {
        fread(&value, sizeof(int), 1, fp2);
        printf("%d ", value);
    }

    printf("\n");
}
