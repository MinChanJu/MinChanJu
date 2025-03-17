'''
project #21 회문 검사 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 단어를 입력받아 회문인지 검사하는 프로그램
Input         : ','로 구분된 3개의 단어
Output        : 3개의 단어의 회문여부
File Name     : practice21.py
History       : 2020.06.06
'''

word = input("','로 구분된 단어 3개를 입력 : ")

one = word.split(', ')[0]
two = word.split(', ')[1]
three = word.split(', ')[2]

print('단어 :', one + ', 역순단어 :',
      one[len(one)-1::-1]+', 회문 :',
      bool(one == one[len(one)-1::-1]))
print('단어 :', two + ', 역순단어 :',
      two[len(two)-1::-1]+', 회문 :',
      bool(two == two[len(two)-1::-1]))
print('단어 :', three + ', 역순단어 :',
      three[len(three)-1::-1]+', 회문 :',
      bool(three == three[len(three)-1::-1]))
