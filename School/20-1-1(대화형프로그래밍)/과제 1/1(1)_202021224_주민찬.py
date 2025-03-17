'''
과제1 문제1
프로그램 이름   : 주차 요금 계산 프로그램
학번            : 202021224
학과            : 수학과
이름            : 주민찬
input           : 입차월, 입차일, 출차월, 출차일
output          : 총 주차기간, 주차 요금
소스코드        : 1(1)_202021224_주민찬.py
작성일          : 2020.05.08
'''

print('[주차 요금 계산 프로그램]')
inM = int(input('입차월: '))
inD = int(input('압차일: '))
outM = int(input('출차월: '))
outD = int(input('출차일: '))
IN = 30*(inM-1) + inM//2 + inD
OUT = 30*(outM-1) + outM//2 +outD
total = OUT-IN+1
money = total*3000
money = money*90/100*int(bool(total>=200))+money-money*int(bool(total>=200))
print('총 주차기간은', total, '일이고,')
print('주차 요금은', int(money), '원 입니다.')
#200일 이상 주차시 10%할인 요금으로 계산
#200일 주차시 요금은 540000원이 나와야 함
