while 1 :
    num = int(input('구구단 몇 단을 출력할까요? '))
    if num == 0 :
        break
    while not(2 <= num <= 9) :
        print('잘못 입력되었습니다.')
        print('다시 입력하세요.')
        num = int(input('구구단 몇 단을 출력할까요? '))
    for n in range(1,10) :
        print(num, 'x', n, '=', num*n)
print('프로그램을 종료합니다.')
