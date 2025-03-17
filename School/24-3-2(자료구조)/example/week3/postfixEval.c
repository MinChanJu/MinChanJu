#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef enum {
    plus,
    minus,
    times,
    divide,
    mod,
    operand,
    eos
} precedence;

precedence getToken(char *symbol, int *n);
void push(int value);
int pop(void);
int eval(void);

int stack[MAX_STACK_SIZE];
int top = -1;
char expression[] = "752*+84/-";
int expr_index = 0;

int main() {
    printf("결과: %d\n", eval());
    return 0;
}

precedence getToken(char *symbol, int *n) {
    *symbol = expression[(*n)++];
    switch (*symbol) {
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("스택 오버플로우!\n");
        exit(1);
    }
}

int pop(void) {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("스택 언더플로우!\n");
        exit(1);
    }
}

int eval(void) {
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    top = -1;

    token = getToken(&symbol, &n);
    while (token != eos) {
        if (token == operand) {
            push(symbol - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (token) {
                case plus: push(op1 + op2); break;
                case minus: push(op1 - op2); break;
                case times: push(op1 * op2); break;
                case divide: push(op1 / op2); break;
                case mod: push(op1 % op2); break;
                default: printf("알 수 없는 연산자\n"); exit(1);
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop();  // 최종 결과 반환
}