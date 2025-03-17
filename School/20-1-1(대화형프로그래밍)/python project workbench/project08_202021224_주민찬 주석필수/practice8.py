'''
project #08 할인율 적용 프로그램

Author        : 주민찬
Details       : 총 금액이 10000원이 넘으면 15% 할인이 되는 프로그램
Input         : 구매하려는 펜과 노트 개수
Output        : 총 금액
File Name     : practice8.py
History       : 2020년 04월 25일
'''

pen = int(input('볼펜 개수 입력 : '))
note = int(input('노트 개수 입력 : '))
if ((pen*1000) + (note*3000)) > 10000 :
    print('총 금액의 15%가 할인되었습니다.')
    total = int(((pen*1000) + (note*3000))*85/100)
else :
    total = int(((pen*1000) + (note*3000)))
print('총 금액 : ' + str(total) +  '원')
