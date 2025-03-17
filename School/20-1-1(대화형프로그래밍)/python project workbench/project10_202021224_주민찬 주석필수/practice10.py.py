gender = input('성별을 입력하세요 (F/M) : ')
age = int(input('나이를 입력하세요 : '))
money = int(input('적립금을 입력하세요 : '))
if gender == 'M' :
    save = money * 2
else :
    if age < 20 :
        save = money * 1.5
    else :
        if age < 30 :
            save = money * 2
        else :
            if age < 40 :
                save = money * 2.5
            else :
                save = money * 3
print('당신의 적립 금액은 '+str(save)+'원 입니다.')
