'''
project #12 입력되는 정수 더하기

Author        : 주민찬
Details       : 그만 할때까지 입력하는 정수를 모두 더하는 프로그램
Input         : 정수, 진행 여부
Output        : 입력된 정수의 총합
File Name     : practice12.py
History       : 2020년 05월 14일
'''

print('이 프로그램은 입력된 정수를 더하는 프로그램입니다.')
repeat = True
total = 0
while repeat :
    a = int(input('정수를 입력하세요 : '))
    total += a
    print('현재까지의 합은 %d입니다.' % total)
    YN=input('계속 하시겠습니까? [Y/N] : ')
    if YN == 'Y' or YN == 'y' :
        YN = 0
    elif YN == 'N' or YN == 'n' :
        repeat = False
    else :
        print('잘못 입력하셨습니다.')
        repeat2 = True
        while repeat2 :
            YN=input('계속 하시겠습니까? [Y/N] : ')
            if YN == 'Y' or YN == 'y' :
                repeat2 = False
            elif YN == 'N' or YN == 'n' :
                repeat = False
                repeat2 = False
            else :
                print('잘못 입력하셨습니다.')
