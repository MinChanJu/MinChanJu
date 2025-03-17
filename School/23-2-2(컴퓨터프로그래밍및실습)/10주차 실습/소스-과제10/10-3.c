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
    printf("파일명을 입력하세요: ");
    scanf("%s", fname);

    fp = fopen(fname, "rb");                                                                         // 파일 열기

    if (fp == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname);                                                // 파일을 열지면 못하면 메세지 출력
    }

    find_total(fp, SIZE);                                                                            // 파일 읽기
    fclose(fp);                                                                                      // 파일 닫기

    return 0;
}

void find_total(FILE* fp, int n) {
    struct product p[SIZE];
    double total = 0.0;

    printf("### 제품 판매 데이터 ###\n");                                                             // 헤더 출력
    for (int i = 0; i < n; ++i) {
        fread(&p[i], sizeof(struct product), 1, fp);
        printf("pid = %s, price = %.2f, number = %.0f\n", p[i].pid, p[i].price, p[i].number);         // 이름,가격,개수 출력
        total += p[i].price * p[i].number;                                                            // total에 가격 곱하기 개수 더하기
    }
    printf("판매 총액: %.2f", total);                                                                 // total 출력
}