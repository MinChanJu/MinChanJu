'''
project #23 성적 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 5명의 성적을 입력받아 평균과 총합 출력
Input         : 5명의 성적
Output        : 평균, 총합
File Name     : practice23.py
History       : 2020,06.13
'''

def total(score) :
    sum = 0
    for x in score :
        sum += x
    print('%5d' % sum, end='')
          
def average(score) :
    sum = 0
    for x in score :
        sum += x
    average = sum/5
    print('%5.2f' % average, end='')

one = int(input('1번 학생 성적: '))
two = int(input('2번 학생 성적: '))
three = int(input('3번 학생 성적: '))
four = int(input('4번 학생 성적: '))
five = int(input('5번 학생 성적: '))

score = [one, two, three, four, five]

print('성적 합계: ', end='')
total(score)
print('점')
print('성적 평균: ', end='')
average(score)
print('점')
