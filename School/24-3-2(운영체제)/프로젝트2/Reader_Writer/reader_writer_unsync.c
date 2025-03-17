#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_BOOKS 30
#define MAX_TITLE_LEN 10
#define BUFFER_SIZE 2048

void *reader(void *arg);
void *writer(void *arg);

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_TITLE_LEN];
} Book;

Book library[MAX_BOOKS];
int book_id = 0;
volatile int stop_flag = 0;

int main() {
    pthread_t readers[3], writers[3];
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    usleep(1000000);
    stop_flag = 1;

    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    return 0;
}

void *reader(void *arg) {
    int id = *((int *)arg);
    while (!stop_flag) {
        char buffer[BUFFER_SIZE] = "";
        char temp[64];

        snprintf(temp, sizeof(temp), "\n----- 독자 %d 도서관 목록 -----\n", id);
        strncat(buffer, temp, BUFFER_SIZE-strlen(buffer)-1);
        for (int i = 0; i < book_id; i++) {
            snprintf(temp, sizeof(temp), "[ID: %d] %s by %s\n", library[i].id, library[i].title, library[i].author);
            strncat(buffer, temp, BUFFER_SIZE-strlen(buffer)-1);
        }
        snprintf(temp, sizeof(temp), "----------- 독자 %d -----------\n\n", id);
        strncat(buffer, temp, BUFFER_SIZE-strlen(buffer)-1);

        printf("%s", buffer);

        usleep(100000);
    }
    return NULL;
}

void *writer(void *arg) {
    int id = *((int *)arg);
    while (!stop_flag) {
        if (book_id >= MAX_BOOKS) {
            printf("편집자 %d: 도서관이 꽉 찼습니다! 책을 더 이상 추가할 수 없습니다.\n", id);
        } else {
            Book new_book;
            new_book.id = book_id;
            snprintf(new_book.title, MAX_TITLE_LEN, "Book-%d", book_id);
            snprintf(new_book.author, MAX_TITLE_LEN, "Author-%d", book_id);

            library[book_id] = new_book;
            book_id++;

            printf("편집자 %d가 책을 추가했습니다: [ID: %d] %s by %s.\n", id, new_book.id, new_book.title, new_book.author);
        }

        usleep(150000);
    }
    return NULL;
}