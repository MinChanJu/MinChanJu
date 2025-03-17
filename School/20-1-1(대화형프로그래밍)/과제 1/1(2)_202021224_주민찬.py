'''
과제1 문제2
프로그램 이름   : 항공권 요금 계산 프로그램
학번            : 202021224
학과            : 수학과
이름            : 주민찬
input           : 예약월, 예약일
output          : 남은 기간, 항공권 요금, 할인율
소스코드        : 1(2)_202021224_주민찬.py
작성일          : 2020.05.08
'''

print('[항공권 요금 계산 프로그램]')
print('출국일은 10월 15일 입니다.')
Month = int(input('예약월: '))
Day = int(input('예약일: '))
print('도착지 번호: 1. 미국, 2. 영국, 3. 중국')
arrival = int(input('도착지 번호 입력: '))
totalD = (Month-1)*30+Month//2-2*int(bool(Month>2))+Day
before = 288-totalD  #288은 1월 1일에서 10월 15일까지의 총 일이다,
if arrival == 1 :
    if 0 <= before < 50 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 0%입니다.')
        print('항공권 요금은 1,000,000원 입니다.')
    elif 50 <= before < 100 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 3%입니다.')
        print('항공권 요금은 970,000원 입니다.')
    elif 100 <= before < 200 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 5%입니다.')
        print('항공권 요금은 950,000원 입니다.')
    else :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 10%입니다.')
        print('항공권 요금은 900,000원 입니다.')
elif arrival == 2 :
    if 0 <= before < 50 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 0%입니다.')
        print('항공권 요금은 800,000원 입니다.')
    elif 50 <= before < 100 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 3%입니다.')
        print('항공권 요금은 776,000원 입니다.')
    elif 100 <= before < 200 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 5%입니다.')
        print('항공권 요금은 760,000원 입니다.')
    else :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 10%입니다.')
        print('항공권 요금은 720,000원 입니다.')
else :
    if 0 <= before < 50 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 0%입니다.')
        print('항공권 요금은 500,000원 입니다.')
    elif 50 <= before < 100 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 3%입니다.')
        print('항공권 요금은 485,000원 입니다.')
    elif 100 <= before < 200 :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 5%입니다.')
        print('항공권 요금은 475,000원 입니다.')
    else :
        print(Month, '월', Day, '일에 예약하면')
        print(before, '일 전으로 할인율은 10%입니다.')
        print('항공권 요금은 450,000원 입니다.')
