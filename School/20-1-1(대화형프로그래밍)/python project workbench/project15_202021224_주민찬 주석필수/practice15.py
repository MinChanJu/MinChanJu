'''
project #15 Euler 상수 구하기

Author        : 주민찬
Details       : 오일러의 수 e를 전개식을 이용하여 구함
Input         : X
Output        : e의 값과 n의 값
File Name     : practice15.py
History       : 2020.05.23
'''

n = 1
e = 1

while 1 :
    sum = 1             # sum 초기화
    for x in range(1,n+1) :
        sum *= x                  # n! 계산
    e += 1/sum
    if 1/sum - 1/(sum*(n+1)) < (10**(-300)) :
        break
    n += 1
print('n =', str(n) + '일 때, 값은', str(e) + '입니다.')
# 1/(166!) - 1/(167!) > 10**(-300) 이고,
# 1/(167!) - 1/(168!) < 10**(-300) 이어서
# n=167에서 누적 중단해야 한다고 생각한다.
