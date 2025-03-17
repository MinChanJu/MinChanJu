#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef enum {
    lparen,   // '(' 왼쪽 괄호
    rparen,   // ')' 오른쪽 괄호
    plus,     // '+'
    minus,    // '-'
    times,    // '*'
    divide,   // '/'
    mod,      // '%'
    operand,  // 숫자 (피연산자)
    eos       // 수식의 끝
} precedence;

// 스택 관련 변수 및 함수
int stack[MAX_STACK_SIZE];
int top = -1;  // 스택의 top을 -1로 초기화하여 스택이 비었음을 나타냄

void push(precedence value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("스택 오버플로우!\n");
        exit(1);
    }
}

precedence pop(void) {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("스택 언더플로우!\n");
        exit(1);
    }
}

// 연산자 우선순위 (isp: 스택 내 우선순위, icp: 스택 외부 우선순위)
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};  // 우선순위
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

// 수식 문자열
char expression[] = "a*(b+c-d)%e";
int expr_index = 0;

// getToken 함수 정의
precedence getToken(char *symbol, int *n) {
    *symbol = expression[(*n)++];
    switch (*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand; // 피연산자 (숫자)
    }
}

// printToken 함수 정의
void printToken(precedence token) {
    switch (token) {
        case plus: printf("+"); break;
        case minus: printf("-"); break;
        case times: printf("*"); break;
        case divide: printf("/"); break;
        case mod: printf("%%"); break;
        default: break;
    }
}

// postfix 변환 함수 정의
void postfix(void) {
    char symbol;
    precedence token;
    int n = 0;
    top = -1;  // 스택을 비어 있는 상태로 초기화
    push(eos);  // eos를 스택에 먼저 넣음

    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if (token == operand) {
            printf("%c", symbol);  // 피연산자는 바로 출력
        } else if (token == rparen) {
            while (stack[top] != lparen) {
                printToken(pop());
            }
            pop();  // 왼쪽 괄호 버림
        } else {
            while (isp[stack[top]] >= icp[token]) {
                printToken(pop());
            }
            push(token);  // 연산자를 스택에 푸시
        }
    }

    while ((token = pop()) != eos) {
        printToken(token);  // 스택에 남아있는 연산자 출력
    }
}

int main() {
    printf("후위 표기법: ");
    postfix();
    printf("\n");
    return 0;
}