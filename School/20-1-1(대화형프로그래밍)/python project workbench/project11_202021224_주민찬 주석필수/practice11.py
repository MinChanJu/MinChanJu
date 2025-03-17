term = int(input('몇 학기를 수료했는지 입력하세요. : '))
score = float(input('평균 학점을 입력하세요.(4.5 만점) : '))

if 1 <= term <= 8 :
    if score >= 3.5 :
        if score >= 4.0 :
            print('전액 장학금을 받을 수 있습니다.')
        else :
            print('등록금의 50%를 장학금으로 받을 수 있습니다.')
    else :
        if score >= 3.0 :
            print('등록금의 30%를 장학금으로 받을 수 있습니다.')
        else :
            print('장학금을 받을 수 없습니다.')
else :
    print('장학금을 받을 수 없습니다.')
