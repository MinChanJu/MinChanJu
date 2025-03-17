'''
project #17 네모 모양 출력 프로그램

Author        : 주민찬
Details       : 입력받은 값을 이용해서 네모 모양을 출력하는 프로그램
Input         : 문자, 가로, 세로
Output        : 문자를 이용한 직사각형
File Name     : practice17.py
History       : 2020.05.28
'''

str = input('문자 입력 : ')
width = int(input('한 줄에 출력할 개수 입력 : '))
high = int(input('출력할 줄 입력 : '))

def rectangle(str, width, high) :
    for x in range(high) :
        for y in range(width) :
            print(str, end=' ')
        print('')
rectangle(str, width, high)
