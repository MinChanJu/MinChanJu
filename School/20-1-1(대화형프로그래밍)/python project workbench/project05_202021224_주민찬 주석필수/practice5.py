'''
project #05. 두 점 사이의 거리 계산

Author       : 주민찬
Details      : 두 점의 좌표를 입력받아 거리를 계산하는 프로그램
Input        : 두 점의 좌표
Output       : 두 점 사이의 거리
File Name    : practice5.py
History      : (1차) 2020년 04월 18일
'''

import math
x1 = int(input('첫 번쨰 점의 x좌표를 입력하세요 : '))
y1 = int(input('첫 번쨰 점의 y좌표를 입력하세요 : '))
x2 = int(input('두 번쨰 점의 x좌표를 입력하세요 : '))
y2 = int(input('두 번쨰 점의 y좌표를 입력하세요 : '))

d = math.sqrt(math.pow((x1-x2),2)+math.pow((y1-y2),2))
print('두 점('+str(x1)+','+str(y1)+'),('+str(x2)+','
      +str(y2)+') 사이의 거리는', str(d)+'입니다.')
