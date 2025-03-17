english = float(input('영어 점수 입력 : '))
history = float(input('국사 점수 입력 : '))

if english + history >= 150 :
    if (english >= 60) and (history >= 60) :
        print('합격입니다.')
    elif (english >= 60) and (history < 60) :
        print('불합격 : 국사 점수가 부족합니다.')
    else :
        print('불합격 : 영어 점수가 부족합니다.')
else :
    print('불합격 : 총합 점수가 부족합니다.')
