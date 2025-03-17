#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 11

int push(char *stack, char ch, int *top);
char pop(char *stack, int *top);
void addPhone(char phoneNumber[][MAX_STACK_SIZE], int *pni, char *stack, int *top, int message);

int main() {
    char InputFile[] = "010753822170102345698701046538987";
    int pni = 0, top = -1, numPhones = strlen(InputFile) / MAX_STACK_SIZE;
    char stack[MAX_STACK_SIZE], phoneNumber[numPhones][MAX_STACK_SIZE];
    
    for (int i = 0; i < strlen(InputFile); i++) {
        int c = push(stack, InputFile[i], &top);
        if (c == 0) {
            addPhone(phoneNumber, &pni, stack, &top, 1);
            c = push(stack, InputFile[i], &top);
        }
    }

    if (push(stack, 'a', &top) == 0) {
        addPhone(phoneNumber, &pni, stack, &top, 0);
    }

    printf("Scanning is completed.\n");
    printf("The list of phone numbers from the input string is.\n");

    for (int i = 0; i < numPhones; i++) {
        for (int j = 0; j < MAX_STACK_SIZE; j++) printf("%c", phoneNumber[i][j]);
        printf("\n");
    }
    
    return 0;
}

int push(char *stack, char ch, int *top) {
    if (*top == MAX_STACK_SIZE-1) {
        printf("Scanning integers has stopped, the stack is full, I will pop out the phone number from the stack.\n");
        return 0;
    }

    stack[++(*top)] = ch;
    return 1;
}

char pop(char *stack, int *top) {
    if (*top == -1) {
        printf("The Stack is now empty, continue scanning.\n");
        return 'a';
    }

    return stack[(*top)--];
}

void addPhone(char phoneNumber[][MAX_STACK_SIZE], int *pni, char *stack, int *top, int message) {
    char tmp;
    int i = MAX_STACK_SIZE-1;

    while (i >= 0 && (tmp = pop(stack, top)) != 'a') {
        phoneNumber[(*pni)][i] = tmp;
        i--;
    }

    printf("phoneNumber%d: ", (*pni)+1);
    for (int i = 0; i < MAX_STACK_SIZE; i++) printf("%c", phoneNumber[(*pni)][i]);
    printf("\n");
    
    if (message == 1) tmp = pop(stack, top);
    (*pni)++;
}