repeat = True

while repeat :
    num = int(input('input data : '))
    if num == 0 :
        print('exit')
        repeat = False
    elif num%2 == 0 :
        print('짝수입니다.')
    else :
        print('홀수입니다.')
