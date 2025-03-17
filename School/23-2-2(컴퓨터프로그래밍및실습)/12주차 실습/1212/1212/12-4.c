#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

int get_integer();                                                  // �Լ� ����
void print_list(NODE* plist);                                       // �Լ� ����
void free_list(NODE* plist);                                        // �Լ� ����

int main() {
    NODE* plist = NULL;

    while (1) {
        int n = get_integer();
        if (n < 0) break;                                           // n�� ������ ����
        NODE* node = (NODE*)malloc(sizeof(NODE));                   // ���� �޸� �Ҵ�
        if (node == NULL) {
            printf("�޸� �Ҵ� ����\n");
            exit(1);
        }
        node->data = n;                                             // node ����
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

    print_list(plist);                                              // print_list �Լ� ����
    free_list(plist);                                               // free_list �Լ� ����
    return 0;   
}

int get_integer() {
    int n;
    printf("���� ������ �Է��Ͻÿ� (�����Ϸ��� -1�� �Է�): ");
    scanf("%d", &n);                                                // ���� �Է�
    return n;                                                       // ���� ��ȯ
}

void print_list(NODE* plist) {
    printf("### �Էµ� ���� ����Ʈ: ");                             // ��� ���
    NODE* temp = plist;
    while (temp != NULL) {
        printf("%d", temp->data);                                   // ������ ���
        if (temp->link != NULL) {
            printf("->");
        }
        else {
            printf("->NULL\n");
        }
        temp = temp->link;                                          // ���� ��ũ�� �̵�
    }
}

void free_list(NODE* plist) {
    NODE* temp;
    while (plist != NULL) {
        temp = plist;
        plist = plist->link;                                        // ���� ��ũ�� �̵�
        free(temp);                                                 // �޸� ��ȯ
    }
}