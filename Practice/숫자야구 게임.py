import random

while 1 :
    game = input('숫자야구게임을 시작하시겠습니까?(Y/N): ')
    if game == 'y' or game == 'Y' or game == 'ㅛ' :
        print('*규칙*')
        print('1. 4자리 숫자로 시작합니다.')
        print('2. 첫번째 자리에는 0이 안들어 갑니다.')
        print('3. 겹치는 숫자는 없습니다.')
        print("4. 성적은 시도횟수가 4이하는 S, 5는 A,\n   6,7은 B, 8,9는 C, 10,11은 D, 12이상은 F")
        a = random.randint(1,9)
        while 1:
            b = random.randint(0,9)
            if a == b :
                continue
            else:
                while 1:
                    c = random.randint(0,9)
                    if c == a or c == b :
                        continue
                    else :
                        while 1:
                            d = random.randint(0,9)
                            if d == a or d == b or d == c :
                                continue
                            else :
                                answer = 1000*a + 100*b + 10*c + d
                                sum1 = 0
                                while 1:
                                    num = input('4자리 숫자를 입력해주세요. : ')
                                    S=0
                                    B=0
                                    if num.isdigit() == True and len(num) == 4 :
                                        L1 = [int(a) for a in num]
                                        if answer == int(num) :
                                            print('4S 정답입니다.')
                                            sum1 = sum1+1
                                            if sum1 <= 4 :
                                                grade = 'S'
                                            elif sum1 == 5 :
                                                grade = 'A'
                                            elif 6 <= sum1 <= 7 :
                                                grade = 'B'
                                            elif 8 <= sum1 <= 9 :
                                                grade = 'C'
                                            elif 10 <= sum1 <= 11 :
                                                grade = 'D'
                                            else :
                                                grade = 'F'
                                            print('총 시도횟수는',str(sum1)+'번이며 성적은',str(grade)+'입니다.')
                                            break
                                        elif L1[0] == L1[1] or L1[0] == L1[2] or L1[0] == L1[3] :
                                            print('다시 입력해주세요.')
                                            continue
                                        elif L1[1] == L1[2] or L1[1] == L1[3] or L1[2] == L1[3] :
                                            print('다시 입력해주세요.')
                                            continue
                                        else :
                                            for x in (0,1,2,3) :
                                                if x == 0:
                                                    if L1[0] == b or L1[0] == c or L1[0] == d :
                                                        B = B+1
                                                    else :
                                                        B=B
                                                elif x == 1:
                                                    if L1[1] == a or L1[1] == c or L1[1] == d :
                                                        B = B+1
                                                    else :
                                                        B=B
                                                elif x == 2:
                                                    if L1[2] == b or L1[2] == a or L1[2] == d :
                                                        B = B+1
                                                    else :
                                                        B=B
                                                else :
                                                    if L1[3] == b or L1[3] == c or L1[3] == a :
                                                        B = B+1
                                                    else :
                                                        B=B
                                        for x in L1 :
                                            if x == a or x == b or x == c or x == d :
                                                S = S+1
                                            else :
                                                continue
                                        S = S-B
                                        if S == 0 and B == 0:
                                            print('OUT')
                                            sum1 = sum1+1
                                        else :
                                            print(str(S)+'S',str(B)+'B')
                                            sum1 = sum1+1
                                    elif num == 'answer':
                                        print(answer)
                                    else :
                                        print('다시 입력해주세요.')
                                        continue
                                break
                            break
                    break
            break
                        
    elif game == 'n' or game == 'N' or game == 'ㅜ' :
        print('게임을 종료합니다.')
        break
    else :
        print('다시 입력해주세요.')
