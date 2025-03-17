# <span style = "color: violet;">운영체제 2024 가을프로젝트</span>

## <span style = "color: skyblue;">수학과 202021224 주민찬</span>

## <span style = "color: red;">공통</span>
- 파이프는 서버로 요청하는 파이프와 서버로부터 응답받는 파이프 두 개 생성
    - 요청 파이프: request_pipe
    - 응답 파이프: response_pipe
- 파일에 쓸 데이터는 최대 1000 bytes로 설정
- 파일명은 최대 100 bytes로 설정
- 하나로 합칠 buffer는 최대 1000+110 bytes로 설정
    - 쓸 데이터 크기 + 파일명 크기 + 파일 억세스 타입 + 읽을 바이트 수
    - 다 합칠 꺼니까 넉넉하게 최대 1110 bytes로 설정

## <span style = "color: red;">server.c</span>
1. 서버 코드는 먼저 request pipe와 response pipe가 있다면 지운다
2. 그 후 request pipe와 response pipe를 mkfifo를 통해 생성
    - 두 named pipe를 생성하는 데 에러가 있다면 에러 메세지 출력 후 종료한다
3. 무한 반복 4~9
4. 그 후 request pipe를 열어 클라이언트가 보낸 요청을 받은 후 닫는다
    - 만약 request pipe를 여는데 에러가 있다면 에러메세지 출력 후 닫는다
5. sscanf를 통해 buffer에서 다음을 가져온다
    - 파일명
    - 파일 억세스 타입
    - 읽을 bytes 수
    - 쓸 데이터 스트링 (공백도 있을 수 있으니 %[^/n]으로 받는다)
6. 만약 파일명이 "종료"일 경우 무한루프를 빠져 나온다.
7. 그 후 child를 fork한다
8. 제대로 fork가 되었을 경우 file_manage 함수를 실행하고 child를 종료한다
    - file_manage 함수
    - 인수
        - 파일명
        - 파일 억세스 타입
        - 읽을 bytes 수
        - 쓸 데이터 스트링
    - 동작 방식
        1. 억세스 타입이 r일 경우
            1. 먼저 파일명을 r로 연다.
                - 만약 파일을 여는 데 에러가 있다면 에러메세지 출력 후 닫는다
            2. 그 후 buffer에 읽을 bytes 수 만큼 읽어 저장한다
            3. 파일을 닫는다
            4. response pipe를 열어 buffer를 클라이언트로 보낸 후 닫는다
                - 만약 response pipe를 여는데 에러가 있다면 에러메세지 출력 후 종료
        2. 억세스 타입이 w일 경우
            1. 먼저 파일명을 w로 연다.
                - 만약 파일을 여는 데 에러가 있다면 에러메세지 출력 후 닫는다
            2. 그 후 쓸 데이터 스트링을 파일에 쓴 후 쓴 bytes를 반환 받는다
            3. 파일을 닫는다
            4. response pipe를 열어 쓴 bytes 수를 클라이언트로 보낸 후 닫는다
9. 제대로 fork가 되지 않았을 경우 wait(NULL)을 실행한다
10. request pipe와 response pipe를 지운다
11. 서버 종료

## <span style = "color: red;">client.c</span>
1. 클라이언트 코드는 먼저 다음을 정의한다.
    - 파일명
    - 파일 억세스 타입
    - 읽을 bytes 수
    - 쓸 데이터 스트링
2. 무한 반복 3~9
3. 사용자로부터 다음을 입력 받는다.
    - 파일명
    - 파일명이 "종료"가 아닐 경우 파일 억세스 타입 (r: 읽기, w: 쓰기)
    - 읽기의 경우: 읽을 bytes 수
    - 쓰기의 경우: 쓸 데이터 스트링
4. 쓸 데이터 스트링의 경우 공백이 포함된 문자열일 수도 있으니 fgets으로 입력한다
    - 마지막 개행 문자 \n도 제거
5. 그 후 입력 받은 모든 것을 buffer로 합친다
6. request pipe를 열어 buffer를 서버로 보낸 후 닫는다
    - 만약 request pipe를 여는데 에러가 있다면 에러메세지 출력 후 종료한다
7. 파일명이 "종료"이면 무한루프를 빠져나온다
8. response pipe를 열어 서버로부터 온 응답을 받은 후 닫음
    - 만약 response pipe를 여는데 에러가 있다면 에러메세지 출력 후 종료한다
9. 서버로부터 받은 응답을 억세스 타입에 맞게 출력한다
    - 억세스 타입 r : 읽은 데이터 출력
    - 억세스 타입 w : 쓴 bytes 수 출력
10. 클라이언트 종료

## <span style = "color: red;">실행방법</span>
1. 터미널에서 프로젝트 디렉토리로 이동한다.
2. 다음을 순차적으로 진행해 서버를 백그라운드로 실행시킨다.
    1. gcc -o server server.c
    2. ./server &
3. 다음을 순차적으로 진행해 클라이언트를 실행시킨다.
    1. gcc -o client client.c
    2. ./client
4. 클라이언트에 요청에 따라 입력한다.
5. 서버를 통해 응답받은 값을 확인한다.
6. 파일명을 "종료"로 입력하여 클라이언트와 서버를 종료시킨다.