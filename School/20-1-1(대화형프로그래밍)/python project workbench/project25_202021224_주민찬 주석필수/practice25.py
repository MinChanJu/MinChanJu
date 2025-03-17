'''
project #25 튜플 활용 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 튜플을 이용한 슬라이싱, 세기, 존재여부 구하기
Input         : 튜플 원소, 방법
Output        : 각 방법의 결과
File Name     : practice25.py
History       : 2020.06.18
'''

print('튜플 활용하기')
tuple = input('튜플에 입력할 자료들을 차례로 입력하세요. 빈칸으로 구분합니다.\n')
tuple = (tuple.split())

while 1 :
    print('작업 할 내용을 입력하세요')
    way = input('q=끝내기, s=슬라이싱, c=세기, i=존재여부 : ')
    if way == 'q' :
        print('프로그램을 종료합니다.')
        break
    elif way == 's' :
        a = int(input('From : '))
        b = int(input('Tp : '))
        print(tuple[a:b])
    elif way == 'c' :
        finddata = input('찾을 자료 값은 : ')
        print(tuple.count(finddata), '번 있습니다')
    elif way == 'i' :
        indata = input('찾을 자료 값은 : ')
        print(indata in tuple)
    else :
        print('잘못 입력하였습니다. q,s,c,l 중에 선택하십시오.')
    
