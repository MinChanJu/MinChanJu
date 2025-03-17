'''
project #29 단어 수 계산 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 영문자로 구성된 문자열을 입력받아 단어 수를 계산하는 프로그램
Input         : 영문자로 구성된 문자열
Output        : 단어 수
File Name     : practice29.py
History       : 2020.06.24
'''

sentence = input('영문자로 구성된 문자열을 입력하세요. : ')
list1 = sentence.split()
set1 = set(list1)

for x in set1 :
    print(x, ':', list1.count(x))
