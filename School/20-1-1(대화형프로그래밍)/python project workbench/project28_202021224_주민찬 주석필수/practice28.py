'''
project #28 줄임말 풀어쓰기 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 줄임말을 번역하여 풀어쓰는 프로그램
Input         : 번역할 문장
Output        : 번역된 문장
File Name     : practice28.py
History       : 2020.06.19
'''

abbreviation = {'B4':'Before', 'TX':'Thanks', 'BBL':'Be Back Later',
                'BCNU':'Be Seeing You', 'HAND':'Have A Nice Day'}

sentence = input('변역할 문장을 입력하시오. : ')
sentence = sentence.split()

for x in abbreviation :
    if bool(x in sentence) :
        a = sentence.index(x)
        sentence[a] = abbreviation[x]
    else :
        continue
for y in sentence :
    print(y, end=' ')
