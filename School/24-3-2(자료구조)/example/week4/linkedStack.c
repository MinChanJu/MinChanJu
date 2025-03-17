#include <stdio.h>
#include <stdlib.h>

typedef struct Stack *StackPointer;
typedef struct Stack {
    int data;
    StackPointer link;
} Stack;

void push(StackPointer *first, int data);
int pop(StackPointer *first);
void printStack(StackPointer *first);

int main() {
    StackPointer first = NULL;
    printStack(&first);
    push(&first,20);
    push(&first,10);
    pop(&first);
    push(&first,5);
    push(&first,7);
    push(&first,30);
    pop(&first);
    push(&first,22);
}

void push(StackPointer *first, int data) {
    StackPointer temp = (StackPointer)malloc(sizeof(StackPointer));
    temp->data = data;
    temp->link = (*first);
    (*first) = temp;
    printStack(first);
}

int pop(StackPointer *first) {
    StackPointer temp = (*first);
    int data;
    (*first) = (*first)->link;
    data = temp->data;
    free(temp);
    printStack(first);
    return data;
}

void printStack(StackPointer *first) {
    StackPointer temp = (*first);
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}