channel = int(input('채널번호를 입력하세요. : '))

if channel < 12 :
    if channel == 5 :
        print('SBS 채널입니다.')
    elif channel == 7 :
        print('KBS 채널입니다.')
    elif channel == 11 :
        print('MBC 채널입니다.')
    else :
        print('입력한 채널은 없습니다. 다시 입력하세요.')
else :
    if channel == 13 :
        print('EBS 채널입니다.')
    elif channel == 17 :
        print('JTBC 채널입니다.')
    elif channel == 19 :
        print('TVN 채널입니다.')
    else :
        print('입력한 채널은 없습니다. 다시 입력하세요.')
