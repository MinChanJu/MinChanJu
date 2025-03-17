'''
Quiz #01. 자릿수합을 계산하는 프로그램
학번: 202021224
작성자: 주민찬
input: 천 단위 정수
output: 자릿수의 합
소스코드: Quiz #01.py
생성날짜: 2020년 4월 9일
'''

number=int(input('천 단위 정수를 입력하세요'))
a=number//1000
b=(number%1000)//100
c=(number%100)//10
d=number%10
print('자릿수의 합', a+b+c+d)
