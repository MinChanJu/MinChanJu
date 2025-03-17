#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char c;
    printf("문자를 입력하시오: ");
    scanf("%c", &c);
    switch (c) {
    case 'C':
        printf("Chat");
        break;
    case 'c':
        printf("Chat");
        break;
    case 'G':
        printf("GPT");
        break;
    case 'g':
        printf("GPT");
        break;
    case 'A':
        printf("AI");
        break;
    case 'ca':
        printf("AI");
        break;
    default:
        printf("Wrong character");
        break;
    }
    return 0;
}