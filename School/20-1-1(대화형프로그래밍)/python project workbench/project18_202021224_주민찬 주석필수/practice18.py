'''
project #18 계산기 프로그램

Author        : 주민찬
Details       : 두 정수를 입력받아 연산을 수행하는 프로그램
Input         : 연산기호, 두 개의 정수
Output        : 연산 결과
File Name     : practice18.py
History       : 2020.05.28
'''

def addition(X,Y) :
    A = X+Y
    return A
def subtraction(X,Y) :
    if X >= Y :
        A = X-Y
        return A
    else :
        A = Y-X
        return A
def multiplication(X,Y) :
    A = X*Y
    return A
def division(X,Y) :
    A = X/Y
    return A
print('계산기 프로그램')
while 1 :
    formula = int(input('1.덧셈 2.뺄셈 3.곱셈 4.나눗셈 5.종료 : '))
    if not(1 <= formula <= 5) :
        print('잘못 입력했습니다. 다시 입력해주세요.')
        continue
    elif formula == 5 :
        print('종료')
        break
    X = float(input('정수 입력1 : '))
    Y = float(input('정수 입력2 : '))

    if formula == 1 :
        result = addition(X,Y)
        print('결과:', result)
    elif formula ==2 :
        result = subtraction(X,Y)
        print('결과:', result)
    elif formula == 3 :
        result = multiplication(X,Y)
        print('결과:', result)
    else :
        result = division(X,Y)
        print('결과:', result)
