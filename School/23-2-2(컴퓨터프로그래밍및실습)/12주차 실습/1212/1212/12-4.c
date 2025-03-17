#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

int get_integer();                                                  // 함수 정의
void print_list(NODE* plist);                                       // 함수 정의
void free_list(NODE* plist);                                        // 함수 정의

int main() {
    NODE* plist = NULL;

    while (1) {
        int n = get_integer();
        if (n < 0) break;                                           // n이 음수면 종료
        NODE* node = (NODE*)malloc(sizeof(NODE));                   // 동적 메모리 할당
        if (node == NULL) {
            printf("메모리 할당 오류\n");
            exit(1);
        }
        node->data = n;                                             // node 연결
        node->link = NULL;
        if (plist == NULL) {
            plist = node;
        }
        else {
            NODE* temp = plist;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = node;
        }
    }

    print_list(plist);                                              // print_list 함수 실행
    free_list(plist);                                               // free_list 함수 실행
    return 0;   
}

int get_integer() {
    int n;
    printf("양의 정수를 입력하시오 (종료하려면 -1을 입력): ");
    scanf("%d", &n);                                                // 정수 입력
    return n;                                                       // 정수 반환
}

void print_list(NODE* plist) {
    printf("### 입력된 연결 리스트: ");                             // 헤딩 출력
    NODE* temp = plist;
    while (temp != NULL) {
        printf("%d", temp->data);                                   // 데이터 출력
        if (temp->link != NULL) {
            printf("->");
        }
        else {
            printf("->NULL\n");
        }
        temp = temp->link;                                          // 다음 링크로 이동
    }
}

void free_list(NODE* plist) {
    NODE* temp;
    while (plist != NULL) {
        temp = plist;
        plist = plist->link;                                        // 다음 링크로 이동
        free(temp);                                                 // 메모리 반환
    }
}