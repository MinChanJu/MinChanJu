# <span style = "color: violet;">운영체제 2024 가을프로젝트 2</span>

## <span style = "color: skyblue;">수학과 202021224 주민찬</span>

## <span style = "color: blue;">공통적인 동작 방식</span>

- Producer, Consumer, Reader, Writer를 각각 3개씩 설정 stop_flag를 설정하여 1초뒤 종료되도록 설정
- 동기화는 semaphore를 사용하여 구현
- thread로 실행

## <span style = "color: red;">Producer/Consumer</span>

Producer Consumer 프로그램은 키오스크를 통해 고객(producer)이 주문을 하고 종업원(consumer)이 그 주문을 수행하는 프로그램입니다.

### 파일 설명

- producer_consumer_unsync.c : 동기화 기능 없이 구현하여 Race Condition 발생
- producer_consumer_sync.c : 동기화 기능을 추가하여 Race Condition 해결
<br>
<br>
- PC_unsync.txt : producer_consumer_unsync.c 파일을 컴파일하고 실행한 결과
- PC_sync.txt : producer_consumer_sync.c 파일을 컴파일하고 실행한 결과

### 실행방법

1. 먼저 터미널에서 프로젝트 디렉토리로 이동
2. 다음 두 명령어를 입력
    - gcc producer_consumer_unsync.c -o producer_consumer_unsync
    - ./producer_consumer_unsync
    <br>
    <br>
    - gcc producer_consumer_sync.c -o producer_consumer_sync
    - ./producer_consumer_sync
3. 결과 확인

## <span style = "color: red;">Reader/Writer</span>

Reader Writer 프로그램은 도서관 시스템으로 독자(reader)가 도서관에 있는 책들을 조회하고 편집자(writer)가 도서관에 책을 추가하는 프로그램입니다.

### 파일 설명

- reader_writer_unsync.c : 동기화 기능 없이 구현하여 Race Condition 발생
- reader_writer_sync.c : 동기화 기능을 추가하여 Race Condition 해결
<br>
<br>
- RW_unsync.txt : reader_writer_unsync.c 파일을 컴파일하고 실행한 결과
- RW_sync.txt : reader_writer_sync.c 파일을 컴파일하고 실행한 결과

### 실행방법

1. 먼저 터미널에서 프로젝트 디렉토리로 이동
2. 다음 두 명령어를 입력
    - gcc reader_writer_unsync.c -o reader_writer_unsync
    - ./reader_writer_unsync
    <br>
    <br>
    - gcc reader_writer_sync.c -o reader_writer_sync
    - ./reader_writer_sync
3. 결과 확인