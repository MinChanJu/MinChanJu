#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

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

int read_count = 0;
sem_t *rw_mutex, *mutex;

int main() {
    pthread_t readers[3], writers[3];
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[3] = {1, 2, 3};

    rw_mutex = sem_open("rw_mutex_sem", O_CREAT, 0666, 1);
    mutex = sem_open("mutex_sem", O_CREAT, 0666, 1);

    if (rw_mutex == SEM_FAILED || mutex == SEM_FAILED) {
        printf("sem_open failed");
        return 1;
    }

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

    sem_close(rw_mutex);
    sem_close(mutex);

    sem_unlink("rw_mutex_sem");
    sem_unlink("mutex_sem");

    return 0;
}

void *reader(void *arg) {
    int id = *((int *)arg);
    while (!stop_flag) {
        sem_wait(mutex);
        read_count++;
        if (read_count == 1) sem_wait(rw_mutex);
        sem_post(mutex);

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

        sem_wait(mutex);
        read_count--;
        if (read_count == 0) sem_post(rw_mutex);
        sem_post(mutex);

        usleep(100000);
    }
    return NULL;
}

void *writer(void *arg) {
    int id = *((int *)arg);
    while (!stop_flag) {
        sem_wait(rw_mutex);

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

        sem_post(rw_mutex);

        usleep(150000);
    }
    return NULL;
}