'''
project #19 GCD, LCM 구하기

Author        : 주민찬
Details       : 두 개의 정수를 입력하여 최대공약수와 최소공배수를 출
Input         : 두 개의 0이 아닌 정수
Output        : 최대 공약수, 최소 공배수
File Name     : practice19.py
History       : 2020.05.29
'''

def GCD(a,b) :
    #a,b,|a|-|b|의 부호에 따라 달라지기 때문에 총 8개의 조건이 나온다.
    while 1:
        if b == 0 :
            GDC = int(a)
            return GDC
        elif (a >= 0 and b >= 0 and a >= b) or (a < 0 and b >= 0 and -a >= b) :
            t = a
            a = b
            b = t%b
        elif (a >= 0 and b >= 0 and a <= b) or (a >= 0 and b < 0 and a <= -b) :
            b = b%a
        elif a >= 0 and b < 0 and a >= -b :
            t = a
            a = b
            b = t%b+b
        elif a < 0 and b >= 0 and -a <= b :
            b = b%a-a
        elif a < 0 and b < 0 and a > b :
            b = b%a-a
        else :
            t = a
            a = b
            b = t%b-b
def LCM(a,b) :
    #a*b의 부호에 따라 양수로 변경 
    if a*b >= 0 :
        LCM = (a*b)/GCD(a,b)
        return LCM
    else :
        LCM = (-a*b)/GCD(a,b)
        return LCM

a = int(input('첫 번째 0이 아닌 정수를 입력하세요 : '))
b = int(input('두 번째 0이 아닌 정수를 입력하세요 : '))
#처음에 0이 들어갈 경우 최소 공배수와  최대 공약수를 구할 수 없다.
c = GCD(a,b)
d = LCM(a,b)
print('%d, %d의 최대 공약수는 %d, 최소 공배수는 %d입니다.' % (a,b,c,d))
