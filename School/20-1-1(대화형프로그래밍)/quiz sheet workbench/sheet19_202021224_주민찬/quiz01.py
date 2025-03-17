dict = {}
for x in range(2) :
    name = input('이름 입력 : ')
    phone = input('전화번호 입력 : ')
    dict[name] = phone
while 1 :
    name = input('검색할 이름 입력 : ')
    if name == 'q' :
        break
    elif bool(name in dict) :
        print(name, '의 전화번호는', dict[name], '입니다.')
    else :
        print(name, '는 리스트에 없습니다.')
