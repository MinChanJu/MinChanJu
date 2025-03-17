'''
project #06. 움직인 시간 계산

Author       : 주민찬
Details      : 미리 저장된 값의 움직인 시간 구하는 프로그랜
Input        : 없음
Output       : 움직인시간
File Name    : practice6.py
History      : (1차) 2020년 04월 18일
'''

import math
d1=3                                       #d1에서의 속도는 4km/h, 시간은 t1
d2=math.sqrt(math.pow(2,2)+math.pow(2,2))  #d2에서의 속도는 2km/h, 시간은 t2
d3=math.sqrt(math.pow(2,2)+math.pow(6,2))  #d3에서의 속도는 8km/h, 시간은 t3
d4=5                                       #d1에서의 속도는 4km/h, 시간은 t4
t1=d1/4
t2=d2/2
t3=d3/8
t4=d4/4
totalH=(t1+t2+t3+t4)//1
totalM=(t1+t2+t3+t4)%1*60//1
totalS=(t1+t2+t3+t4)%1*60%1*60
print('구간별 소요 시간')
print('=================================')
print('                거리     소요시간')
print('첫 번째 구간'+'\t%5.4f \t %5.4f'% (d1, t1))
print('두 번째 구간'+'\t%5.4f \t %5.4f'% (d2, t2))
print('세 번째 구간'+'\t%5.4f \t %5.4f'% (d3, t3))
print('네 번째 구간'+'\t%5.4f \t %5.4f'% (d4, t4))
print('=================================')
print('전체 소요 시간\t'+'%d시간%d분%d초'% (totalH, totalM, totalS))
