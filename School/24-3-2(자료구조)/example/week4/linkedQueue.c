#include <stdio.h>
#include <stdlib.h>

typedef struct Queue *QueuePointer;
typedef struct Queue {
    int data;
    QueuePointer link;
} Queue;

void Enqueue(QueuePointer *front, QueuePointer *rear, int data);
int Dequeue(QueuePointer *front);
void printQueue(QueuePointer *front);

int main() {
    QueuePointer front = NULL, rear = NULL;
    printQueue(&front);
    Enqueue(&front, &rear, 32);
    Enqueue(&front, &rear, 22);
    Dequeue(&front);
    Enqueue(&front, &rear, 14);
    Enqueue(&front, &rear, 59);
    Enqueue(&front, &rear, 20);
    Dequeue(&front);
    Enqueue(&front, &rear, 30);
}

void Enqueue(QueuePointer *front, QueuePointer *rear, int data) {
    QueuePointer temp = (QueuePointer)malloc(sizeof(QueuePointer));
    temp->data = data;
    temp->link = NULL;
    if (!(*front)) (*front) = temp;
    else (*rear)->link = temp;
    (*rear) = temp;
    printQueue(front);
}

int Dequeue(QueuePointer *front) {
    QueuePointer temp = (*front);
    int data;
    data = temp->data;
    (*front) = temp->link;
    free(temp);
    printQueue(front);
    return data;
}

void printQueue(QueuePointer *front) {
    QueuePointer temp = (*front);
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}