'''
project #16 이진수를 십진수로 변화하기

Author        : 주민찬
Details       : 이진수를 십진수로 바꿔주는 프로그램
Input         : 이진수
Output        : 십진수
File Name     : practice16.py
History       : 2020.05.23
'''

a = 1

while a :
    two = int(input('하나의 이진수를 입력하세요 : '))
    n = 1
    while two//(10**n) >= 10 :
        n += 1
    for x in range(n+1) :
        b = (two%10**(x+1))//10**x
        if b == 1 or b == 0 :
            ten = 0
            for y in range(n+1) :
                t = ((two%10**(y+1))//10**y)*(2**y)
                ten += t
        else :
            print('잘못된 이진수입니다. 다시 입력하세요.')
            ten = 0
            break
        a = 0
print('이진수', str(two) + '을 십진법으로 표현한 값 =', ten)
