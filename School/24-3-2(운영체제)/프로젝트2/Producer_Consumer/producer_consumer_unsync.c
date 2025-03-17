#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_MENU_LEN 10

void *producer(void *arg);
void *consumer(void *arg);

typedef struct {
    int id;
    char menu[MAX_MENU_LEN];
} Order;

Order orders[BUFFER_SIZE];
int out = 0, in = 0, order_id = 0;
volatile int stop_flag = 0;

int counter = 0;

int main() {
    pthread_t producers[3], consumers[3];
    int producer_ids[3] = {1, 2, 3};
    int consumer_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    usleep(1000000);
    stop_flag = 1;

    for (int i = 0; i < 3; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    return 0;
}

void *producer(void *arg) {
    int id = *((int *)arg);
    while (!stop_flag) {
        while (counter == BUFFER_SIZE);

        Order new_order;
        new_order.id = order_id++;
        snprintf(new_order.menu, MAX_MENU_LEN, "menu-%d", new_order.id);
        
        orders[in] = new_order;
        in = (in+1)%BUFFER_SIZE;
        counter++;

        printf("고객 %d는 키오스크를 통해 [id %d] %s를 주문.\n", id, new_order.id, new_order.menu);

        usleep(100000);
    }
    return NULL;
}

void *consumer(void *arg) {
    int id = *((int *)arg);
    while (!stop_flag) {
        while (counter == 0);

        Order menu = orders[out];
        out = (out+1)%BUFFER_SIZE;
        counter--;

        printf("종업원 %d: [id %d] %s가 나왔습니다.\n", id, menu.id, menu.menu);

        usleep(150000);
    }
    return NULL;
}