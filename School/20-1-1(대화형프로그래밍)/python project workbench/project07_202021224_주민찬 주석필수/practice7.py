'''
project #07. 학사경고 판단

Author       : 주민찬
Details      : 평군학점과 F학점의 개수로 학사경고 여부를 판단하는 프로그램
Input        : 평균 학점과 F학점의 개수
Output       : 학사경고 여부
File Name    : practice7.py
History      : (1차) 2020년 04월 23일
'''

name = input('이름을 입력하세요 : ')
average = float(input('평균 학점을 입력하세요 : '))
F = int(input('F학점의 개수를 입력하세요 : '))
print(name, '학생은 학사경고가', F>=3 or average<=1, '입니다')
