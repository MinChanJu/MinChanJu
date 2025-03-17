'''
과제2 모양 출력 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 모양 번호, 크기를 입력받아 모양을 출력하는 프로그램
Input         : 모양 번호, 크기
Output        : 모양
File Name     : 과제2_202021224_주민찬.py
History       : 2020.05.30
'''

#알파벳 모래시계 함수
def alphabet_sandglass(size) :
    if size%2 == 0 :                        #짝수
        z = size//2
        for a in range(z) :
            code = 97
            for b in range(2*z-size) :
                print(' ', end='')
            for c in range(size//2) :
                print(chr(code), end=' ')
                code += 1
            for d in range(size//2) :
                code -= 1
                print(chr(code), end=' ')
            print('')
            size -= 2
        size = 2
        for e in range(z) :
            code = 97
            for f in range(2*z-size) :
                print(' ', end='')
            for g in range (size//2) :
                print(chr(code), end=' ')
                code += 1
            for h in range(size//2) :
                code -= 1
                print(chr(code), end=' ')
            print('')
            size += 2
    else :                                  #홀수
        z = size//2
        for i in range(z) :
            code = 97
            for j in range(2*z-size+1) :
                print(' ', end='')
            for k in range(size//2) :
                print(chr(code), end=' ')
                code += 1
            print(chr(code), end=' ')
            for l in range(size//2) :
                code -= 1
                print(chr(code), end=' ')
            print('')
            size -= 2
        size = 2
        for m in range(2*z) :
            print(' ', end='')
        print(chr(97))
        for n in range(z) :
            code = 97
            for o in range(2*z-size) :
                print(' ', end='')
            for p in range (size//2) :
                print(chr(code), end=' ')
                code += 1
            print(chr(code), end=' ')
            for q in range(size//2) :
                code -= 1
                print(chr(code), end=' ')
            print('')
            size += 2

#숫자 리본 함수
def number_ribbon(size) :
    if size%2 == 0 :                        #짝수
        start = 1
        for a in range(size) :
            for b in range(a+1) :
                print(start, end=' ')
                start += 1
            for c in range(size-a-1) :
                print('  ', end='  ')
            for d in range(a+1) :
                start -= 1
                print(start, end=' ')
            print('')
        for e in range(size) :
            for f in range(size-e) :
                print(start, end=' ')
                start += 1
            for g in range(e) :
                print('  ', end='  ')
            for h in range(size-e) :
                start -= 1
                print(start, end=' ')
            print('')
    else :                                  #홀수
        start = 1
        for i in range(size) :
            for j in range(i) :
                print(start, end=' ')
                start += 1
            for k in range(2*(size-i-1)) :
                print(' ', end=' ')
            print('  ', end='')
            for l in range(i) :
                start -= 1
                print(start, end=' ')
            print('')
        for m in range(size) :
            print(start, end=' ')
            start += 1
        start -= 1
        for n in range(size-1) :
            start -= 1
            print(start, end=' ')
        print('')
        for o in range(size-1) :
            for p in range(size-o-1) :
                print(start, end=' ')
                start += 1
            for q in range(2*o) :
                print('  ', end='')
            print('  ', end='')
            for r in range(size-o-1) :
                start -= 1
                print(start, end=' ')
            print('')

while 1:
    print('[ 모양 출력 프로그램 ]')
    print('[ 모양 번호: 1. 알파벳 모래시계, 2. 숫자 리본 ]')
    shape = int(input('출력할 모양을 선택하세요 : '))
    if not(1 <= shape <= 2) :
        print('잘못 입력했습니다.')
        continue
    elif shape == 1 :
        size = int(input('크기를 입력하세요(3~52) : '))
        alphabet_sandglass(size)
        break
    else :
        size = int(input('크기를 입력하세요(3~9) : '))
        number_ribbon(size)
        break
