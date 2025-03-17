
import random

while 1:
    a = input('up&down 게임을 시작하시겠습니까?(y/n) : ')
    if a == 'y' or a == 'Y' :
        answer = random.randint(1,100)
        while 1:
            num = input('1~100까지의 숫자를 입력해주세요. : ')
            if num.isdigit() == True :
                num = int(num)
                if num == answer :
                    print('정답입니다')
                    break
                elif 1 <= num <= 100 :
                    if num < answer :
                        print(num, '은 UP')
                    else :
                        print(num, '은 DOWN')
                else :
                    print('다시 입력해주세요')
            else :
                print('다시 입력해주세요')
    elif a == 'n' or a == 'N' :
        print('게임을 종료합니다')
        break        
    else :
        print('다시 입력해주세요')
