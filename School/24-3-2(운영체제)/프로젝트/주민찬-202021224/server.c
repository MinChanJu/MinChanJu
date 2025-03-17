#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define REQUEST_PIPE "./request_pipe"
#define RESPONSE_PIPE "./response_pipe"
#define BUFFER_SIZE 1000

void file_manage(char *file_name, char access_type, char *data, int bytes_to_read);

int main() {
    unlink(REQUEST_PIPE);
    unlink(RESPONSE_PIPE);

    if (mkfifo(REQUEST_PIPE, 0666) == -1 || mkfifo(RESPONSE_PIPE, 0666) == -1) {
        printf("named pipe 생성 실패\n");
        exit(1);
    }

    while (1) {
        int request_pipe = open(REQUEST_PIPE, O_RDONLY);
        if (request_pipe == -1) {
            printf("request pipe 열기 실패\n");
            exit(1);
        }

        char buffer[BUFFER_SIZE+110];
        read(request_pipe, buffer, sizeof(buffer));
        close(request_pipe);

        char file_name[100];
        char access_type;
        int bytes_to_read;
        char data[BUFFER_SIZE];

        sscanf(buffer, "%s %c %d %[^\n]", file_name, &access_type, &bytes_to_read, data);

        if (strcmp(file_name, "종료") == 0) {
            printf("서버 종료 명령을 받았습니다.\n");
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            file_manage(file_name, access_type, data, bytes_to_read);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    unlink(REQUEST_PIPE);
    unlink(RESPONSE_PIPE);
    printf("파이프 삭제\n");

    printf("서버 종료\n");

    return 0;
}

void file_manage(char *file_name, char access_type, char *data, int bytes_to_read) {
    if (access_type == 'r') {
        FILE *file = fopen(file_name, "r");
        if (!file) {
            printf("읽기 위한 파일 열기 실패\n");
            exit(1);
        }

        char buffer[bytes_to_read+1];
        fread(buffer, 1, bytes_to_read, file);
        buffer[bytes_to_read] = '\0';

        fclose(file);

        int response_pipe = open(RESPONSE_PIPE, O_WRONLY);
        if (response_pipe == -1) {
            printf("response pipe 열기 실패\n");
            exit(1);
        }

        write(response_pipe, buffer, bytes_to_read + 1);
        close(response_pipe);
    } else if (access_type == 'w') {
        FILE *file = fopen(file_name, "w");
        if (!file) {
            printf("쓰기 위한 파일 열기 실패\n");
            exit(1);
        }

        int bytes_written = fwrite(data, sizeof(char), strlen(data), file);

        fclose(file);

        int response_pipe = open(RESPONSE_PIPE, O_WRONLY);
        if (response_pipe == -1) {
            printf("response pipe 열기 실패\n");
            exit(1);
        }

        write(response_pipe, &bytes_written, sizeof(int));
        close(response_pipe);
    }
}