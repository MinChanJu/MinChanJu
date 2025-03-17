'''
project #27 커피 전문점 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 메뉴 이름을 입력 받아 가격을 알아보는 프로그램
Input         : 메뉴 이름
Output        : 가격 또는 오류 메세지
File Name     : practice27.py
History       : 2020.06.19
'''

menu = {'Americano':'4000원', 'Cafe latte':'4500원',
        'Cappucino':'5000원', 'Vanilla latte':'5500원'}
while 1 :
    drink = input('메뉴입력 (q = 종료) : ')
    if drink == 'q' :
        break
    elif bool(drink.capitalize() in menu) :
        print(drink.capitalize()+'는', menu[drink.capitalize()], '입니다.')
    else :
        print('메뉴에 없는 커피를 입력했습니다.')
