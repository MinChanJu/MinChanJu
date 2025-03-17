'''
project #09 놀이기구 입장 제한 프로그램

Author        : 주민찬
Details       : 놀이기구 입장이 가능한지 판단해주는 프로그램
Input         : 키와 몸무게
Output        : 놀이기구 입장여부
File Name     : practice9.py
History       : 2020년 04월 25일
'''

print('이 놀이기구를 타려면 다음의 지시사항을 따라주세요.')
height = float(input('키를 입력하세요. : '))
weight = float(input('몸무게를 입력하세요. : '))
if height<=150 and weight <= 40 :
    print('입장가능합니다.')
else :
    print('입장이 불가능합니다.')
    print('다른 놀이기구를 이용해주세요')
