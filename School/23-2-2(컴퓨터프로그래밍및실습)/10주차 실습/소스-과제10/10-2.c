#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare_files(FILE* fp1, FILE* fp2);

int main(void) {
    char fname1[100], fname2[100];
    FILE* fp1, * fp2;

    printf("첫번째 파일: ");
    scanf("%s", fname1);
    printf("두번째 파일: ");
    scanf("%s", fname2);
    fp1 = fopen(fname1, "r");                                                 // 파일 열기
    if (fp1 == NULL) {
        printf("파일 %s을(를) 열 수 없습니다.\n", fname1);                    // 파일을 열지 못하면 메세지 출력
    }

    fp2 = fopen(fname2, "r");                                                 // 파일 열기
    if (fp2 == NULL) {
        printf("파일 %s을(를) 열 수 없습니다.\n", fname2);                    // 파일을 열지 못하면 메세지 출력
    }

    compare_files(fp1, fp2);                                                  // 두 파일 비교

    fclose(fp1);                                                              // 파일 닫기
    fclose(fp2);                                                              // 파일 닫기

    return 0;
}

void compare_files(FILE* fp1, FILE* fp2) {
    char buffer1[1024], buffer2[1024];
    char* bu1, * bu2;
    while (1) {
        bu1 = fgets(buffer1, sizeof(buffer1), fp1);
        bu2 = fgets(buffer2, sizeof(buffer2), fp2);
        if (bu1 == NULL || bu2 == NULL) {                                     // 두 파일 중 하나라도 끝나면 멈춤
            break;
        }
        if (strcmp(buffer1, buffer2) != 0) {                                  // 두 파일 비교 중 다르면 출력
            printf("<< %s", buffer1);
            printf("\n>> %s", buffer2);
        }
    }
}