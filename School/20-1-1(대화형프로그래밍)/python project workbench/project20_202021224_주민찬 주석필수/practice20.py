'''
project #20 암호화 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 사용자가 입력한 문자열을 암호화
Input         : 원본 텍스트
Output        : 암호 텍스트
File Name     : practice20.py
History       : 2020.06.04
'''

original = input('원본 텍스트: ')
print('암호 텍스트: ', end='')
x = 0
while 1 :
    if original[x:] == '' :    #문자의 자릿수가 더 커질 경우 멈춤
        break
    A = ord(original[x])+5
    A = chr(A)
    print(A, end='')
    x += 1
