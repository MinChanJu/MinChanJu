'''
과제3 도서 대출 반납 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 도서의 대출과 반납 프로그램
Input         : 대출, 반납
Output        : 결과
File Name     : 과제3_202021224_주민찬.py
History       : 2020.06.27
'''

def borrow() :                      # 대출 함수
    while 1 :
            print('')
            borrow_day = input('>>> [대출일] 년, 월, 일을 입력하세요.(예:2020 JAN 05) : ')
            borrow_day = borrow_day.split()
            if bool(borrow_day[1] in month) == True :
                borrow_day[1] = str(month[borrow_day[1]])
                borrow_day = borrow_day[0]+'년 '+borrow_day[1]+'월 '+borrow_day[2]+'일'
                while 1 :
                    count = int(input('>>> 대출 권수 입력 : '))
                    if count + len(book_list) > 3 :
                        print('대출 가능한 권수를 초과했습니다.')
                    else :
                        break
                for x in range(count) :
                    borrow_book = input('>>> 대출할 도서명 입력 : ')
                    book_list[borrow_book] = borrow_day
                print('')
                break
            else :
                print('월 입력이 잘못되었습니다.')
                continue

def returns() :                     # 반납 함수
    while 1 :
            print('\n'+'*'*19 + '현재 대출 현황' + '*'*19)
            key = list(book_list.keys())
            value = list(book_list.values())
            for x in range(len(book_list)) :
                print('[{}] 대출일: {}, 도서명: {}' .format(x+1, value[x], key[x]))
            print('*'*52, '\n')
            while 1 :
                return_day = input('>>> [반납일] 년, 월, 일을 입력하세요.(예:2020 JAN 05) : ')
                return_day = return_day.split()
                if bool(return_day[1] in month) == True :
                    return_day[1] = str(month[return_day[1]])
                    return_day = return_day[0]+'년 '+return_day[1]+'월 '+return_day[2]+'일'
                    return_book = input('>>> 반납할 도서명 입력 : ')
                    print('\n< {} > 도서의 대출일은 {}이고, 반납일은 {}입니다.' .format(return_book, book_list[return_book], return_day))
                    day = count_day(int(book_list[return_book][:4]), int(book_list[return_book][6:8]), int(book_list[return_book][10:12]),
                                    int(return_day[:4]), int(return_day[6:8]), int(return_day[10:12]))
                    if day > 50 :
                        late_day = day-50
                        print('대출 기간은 총', str(day)+'일입니다.')
                        print('\n'+str(late_day)+'일이 연체되었습니다.')
                        print('반납이 완료되었습니다.')
                    else :
                        print('대출 기간은 총', str(day)+'일입니다.')
                        print('\n반납이 완료되었습니다.')
                    del book_list[return_book]
                    print('')
                    break
                else :
                    print('월 입력이 잘못되었습니다.')
                    continue
            break

def count_day(Y1, M1, D1, Y2, M2, D2) :     # 일수 계산 함수
    if leap_year(Y1) == True and leap_year(Y2) == True :
        count = 1
        n = 0
        while Y1<Y2 :
            Y1 += 4
            if leap_year(Y1) == True :
                count += 1
            else :
                continue
            n += 1
        Y1 -= 4*n
        if M1 > 2 :
            day1 = (M1-1)*30 + M1//2 - 1 + D1
        else :
            day1 = (M1-1)*31 + D1
        if M2 > 2 :
            day2 = (M2-1)*30 + M2//2 - 1 + D2
        else :
            day2 = (M2-1)*31 + D2
        total_term = day2 + 365*(Y2-Y1)+count - day1-1
        return total_term
    elif leap_year(Y1) == True and leap_year(Y2) == False :
        count = 1
        n = 0
        while Y1<Y2 :
            Y1 += 4
            if leap_year(Y1) == True :
                count += 1
            else :
                continue
            n += 1
        Y1 -= 4*n
        if M1 > 2 :
            day1 = (M1-1)*30 + M1//2 - 1 + D1
        else :
            day1 = (M1-1)*31 + D1
        if M2 > 2 :
            day2 = (M2-1)*30 + M2//2 - 2 + D2
        else :
            day2 = (M2-1)*31 + D2
        total_term = day2 + 365*(Y2-Y1)+count - day1-1
        return total_term
    elif leap_year(Y1) == False and leap_year(Y2) == True :
        count = 0
        n = 0
        while Y1<Y2 :
            Y2 -= 4
            if leap_year(Y2) == True :
                count += 1
            else :
                continue
            n += 1
        Y2 += 4*n
        if M1 > 2 :
            day1 = (M1-1)*30 + M1//2 - 2 + D1
        else :
            day1 = (M1-1)*31 + D1
        if M2 > 2 :
            day2 = (M2-1)*30 + M2//2 - 1 + D2
        else :
            day2 = (M2-1)*31 + D2
        total_term = day2 + 365*(Y2-Y1)+count - day1-1
        return total_term
    else :
        count = 0
        n = 0
        while Y1<Y2 :
            Y1 += 1
            if leap_year(Y1) == True :
                count += 1
            else :
                continue
            n += 1
        Y1 -= n
        if M1 > 2 :
            day1 = (M1-1)*30 + M1//2 - 2 + D1
        else :
            day1 = (M1-1)*31 + D1
        if M2 > 2 :
            day2 = (M2-1)*30 + M2//2 - 2 + D2
        else :
            day2 = (M2-1)*31 + D2
        total_term = day2 + 365*(Y2-Y1)+count - day1-1
        return total_term
    print(total_term)

def leap_year(year) :                   # 윤년 계산 함수
    if year%4 == 0 :
        if year%100 == 0 and not(year%400 == 0) :
            return False
        else :
            return True
    else :
        return False

month = {'JAN':'01', 'FEB':'02', 'MAR':'03', 'APR':'04', 'MAY':'05', 'JUN':'06', 'JUL':'07', 'AUG':'08', 'SEP':'09', 'OCT':'10', 'NOV':'11', 'DEC':'12'}        # 달 입력 딕셔너리
book_list = {}                              # 책 입력 딕셔너리
cont = 'y'


print('[ 도서 대출 반납 프로그램 ]')

while 1 :                                   # main()함수
    if cont == 'n' :
        break
    print('\n[ 1. 대출, 2. 반납 ]')
    service = input('>>> 서비스 번호를 선택하세요 : ')
    if service == '1' :
        borrow()
        cont = input('>>> 계속 하시겠습니까?(y 또는 n) : ')
    elif service == '2' :
        if len(book_list) == 0 :
            print('\n반납할 도서가 없습니다.')
            continue
        returns()
        cont = input('>>> 계속 하시겠습니까?(y 또는 n) : ')
    else :
        print('서비스 번호를 잘못 입력했습니다.')
