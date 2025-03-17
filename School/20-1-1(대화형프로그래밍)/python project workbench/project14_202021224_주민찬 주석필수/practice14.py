'''
project #14 삼각형 만들기

Author        : 주민찬
Details       : 그만 할때까지 입력하는 정수를 모두 더하는 프로그램
Input         : x
Output        : *모양을 이용한 직감 삼각형
File Name     : practice14.py
History       : 2020년 05월 21일
'''


for n in range(1,6) :
    for k in range(1,6 - n) :
        print(' ', end='')
    for j in range(1,n) :
        print('*', end='')
    print('*')
