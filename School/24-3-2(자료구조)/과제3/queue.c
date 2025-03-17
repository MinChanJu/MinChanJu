#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 6
#define MAX_NAME_SIZE 21

void arrival(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *front, int *rear);
void treatment(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *front, int *rear);
void enqueue(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *rear, char name[MAX_NAME_SIZE]);
char* dequeue(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *front);

int main() {
    char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE];
    int front = 0, rear = 0;

    while (1) {
        int hospital_select;
        printf("\nWelcome to the Hospital care service. Please select the number of the function you want.\n");
        printf("1. Hospital Arrival 2. Proceed treatment 3. Service Cancellation \n");
        scanf("%d", &hospital_select);

        switch (hospital_select) {
            case 1:
                arrival(waiting, &front, &rear);
                break;
            case 2:
                treatment(waiting, &front, &rear);
                break;
            case 3:
                printf("Terminate the program\n");
                return 0;
            default:
                printf("You entered the wrong number.");
                break;
        }
    }

    return 0;
}

void arrival(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *front, int *rear) {
    if ((*rear+1)%MAX_QUEUE_SIZE == *front) { 
        printf("There is no space for new medical treatments, try again next time.\n");
        return;
    }

    int arrival_select;
    char name[MAX_NAME_SIZE];
    printf("The current waiting number is %d.", ((*rear)-(*front)+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE);
    printf("Please select the number of the function you want from the following.\n");
    printf("1. Waiting registration 2. Cancellation \n");
    scanf("%d", &arrival_select);

    switch (arrival_select) {
        case 1:
            printf("Please register the name of the waiting person: ");
            scanf("%s", name);
            enqueue(waiting, rear, name);
            printf("Thank you\n");
            break;
        case 2:
            printf("Cancellation of the hospital arrival\n");
            break;
        default:
            printf("You entered the wrong number.\n");
            arrival(waiting, front, rear);
            break;
    }
}

void treatment(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *front, int *rear) {
    if (*front == *rear) {
        printf("No patient waiting\n");
        return;
    }
    
    char patient[MAX_NAME_SIZE];
    strcpy(patient, dequeue(waiting, front));
    printf("patient: %s\n", patient);
}

void enqueue(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *rear, char name[MAX_NAME_SIZE]) {
    (*rear) = ((*rear)+1)%MAX_QUEUE_SIZE;
    strncpy(waiting[(*rear)], name, MAX_NAME_SIZE); 
}

char* dequeue(char waiting[MAX_QUEUE_SIZE][MAX_NAME_SIZE], int *front) {
    (*front) = ((*front)+1)%MAX_QUEUE_SIZE;
    return waiting[*front];
}