#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int eval_exp(char s[]);

int main() {
    char s[100];

    while (1) {
        printf("수학 연산을 입력하시오: ");
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0'; // Remove the newline character

        if (strcmp(s, "-1") == 0) {
            break; // Exit the infinite loop if input is "-1"
        }

        int result = eval_exp(s);
        printf("연산의 결과: %d\n", result);
    }

    return 0;
}

int eval_exp(char s[]) {
    char* token;
    char op[10];
    int x, y;

    // Get the first operand
    token = strtok(s, " ");
    x = atoi(token);

    // Get the operator
    token = strtok(NULL, " ");
    strcpy(op, token);

    // Get the second operand
    token = strtok(NULL, " ");
    y = atoi(token);

    // Perform the calculation based on the operator
    if (strcmp(op, "add") == 0) {
        return x + y;
    }
    else if (strcmp(op, "sub") == 0) {
        return x - y;
    }
    else if (strcmp(op, "mult") == 0) {
        return x * y;
    }
    else if (strcmp(op, "div") == 0) {
        if (y != 0) {
            return x / y;
        }
        else {
            printf("Error: Division by zero\n");
            return 0;
        }
    }
    else if (strcmp(op, "mod") == 0) {
        if (y != 0) {
            return x % y;
        }
        else {
            printf("Error: Modulo by zero\n");
            return 0;
        }
    }
    else {
        printf("Error: Invalid operator\n");
        return 0;
    }
}