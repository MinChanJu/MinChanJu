#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2���� ���� �� �ִ밪�� ���ϴ� ��ũ�� MAX(x, y)
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// 3���� ���� �� �ִ밪�� ���ϴ� ��ũ�� GET_MAX(x, y, z)
#define GET_MAX(x, y, z) MAX(MAX(x, y), z)

int main() {
    int x, y, z;

    // ����ڷκ��� 3���� ���� �Է� �ޱ�
    printf("3���� ������ �Է��Ͻÿ�: ");
    scanf("%d %d %d", &x, &y, &z);

    // ��ũ�� GET_MAX�� �̿��Ͽ� �ִ밪 ���
    printf("���� (%d, %d, %d) �� �ִ밪�� %d�Դϴ�.\n", x, y, z, GET_MAX(x, y, z));

    return 0;
}