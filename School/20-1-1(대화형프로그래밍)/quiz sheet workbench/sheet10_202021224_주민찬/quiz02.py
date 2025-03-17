x = int(input('양의 정수 x 입력 : '))
y = int(input('양의 정수 y 입력 : '))
total = 0

if x > y :
    print('잘못 입력되었습니다.')
    print('프로그램을 종료합니다.')
else :
    for n in range(x,y+1) :
        total += n
    print('%d부터 %d까지 더한 값은 %d입니다.' % (x,y,total))
