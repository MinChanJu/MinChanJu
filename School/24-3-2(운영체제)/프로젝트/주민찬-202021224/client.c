#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define REQUEST_PIPE "./request_pipe"
#define RESPONSE_PIPE "./response_pipe"
#define BUFFER_SIZE 1000

int main() {
    char file_name[100];
    char access_type;
    int bytes_to_read = 0;
    char data[BUFFER_SIZE] = {0};

    while (1) {
        printf("===================================================================\n");
        printf("파일명: ");
        scanf("%s", file_name);

        access_type = 'a';
        if (strcmp(file_name,"종료") != 0) {
            printf("파일 억세스 타입 (r: 읽기, w: 쓰기): ");
            scanf("\n%c", &access_type);
        }

        if (access_type == 'r') {
            printf("읽을 bytes 수: ");
            scanf("%d", &bytes_to_read);
        } else if (access_type == 'w') {
            printf("쓸 데이터 스트링: ");
            getchar();
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;
        }

        char buffer[BUFFER_SIZE+110];
        snprintf(buffer, sizeof(buffer), "%s %c %d %s", file_name, access_type, bytes_to_read, data);

        int request_pipe = open(REQUEST_PIPE, O_WRONLY);
        if (request_pipe == -1) {
            printf("request pipe 열기 실패\n");
            exit(1);
        }

        write(request_pipe, buffer, strlen(buffer) + 1);
        close(request_pipe);

        printf("서버에게 요청 보냄\n");

        if (strcmp(file_name, "종료") == 0) break;

        int response_pipe = open(RESPONSE_PIPE, O_RDONLY);
        if (response_pipe == -1) {
            printf("response pipe 열기 실패\n");
            exit(1);
        }

        if (access_type == 'r') {
            char read_data[BUFFER_SIZE];
            read(response_pipe, read_data, sizeof(read_data));
            printf("읽은 데이터: %s\n", read_data);
        } else if (access_type == 'w') {
            int bytes_written;
            read(response_pipe, &bytes_written, sizeof(int));
            printf("쓴 bytes 수: %d\n", bytes_written);
        }
        close(response_pipe);

        printf("서버에게 응답 받음\n");
    }

    printf("클라이언트 종료\n");

    return 0;
}