'''
project #22 음계 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 피아노의 건반을 저장해놓은 list를 이용하여 요구사항 출력
Input         : X
Output        : 피아노 건반, (1,4,5)도 화음, 학교종의 음계
File Name     : practice22.py
History       : 2020.06.11
'''

piano = ['도', '레', '미', '파', '솔', '라', '시']
one = piano[0]+piano[2]+piano[4]
four = piano[3]+piano[5]+piano[0]
five = piano[4]+piano[6]+piano[1]
school_bell = [piano[4]]*2+[piano[5]]*2+[piano[4]]*2+[piano[2]]

print('피아노의 건반 : ', piano)
print('다장조의 1도 화음 : ', one)
print('다장조의 4도 화음 : ', four)
print('다장조의 5도 화음 : ', five)
print('학교종의 음계 : ', school_bell)
