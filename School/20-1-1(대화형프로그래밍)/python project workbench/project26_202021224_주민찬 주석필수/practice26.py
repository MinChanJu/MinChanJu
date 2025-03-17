'''
project #26 성적 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 1~4반 성적 평균을 출력하는 프로그램
Input         : X
Output        : 1~4반 성적 평균
File Name     : practice.py
History       : 2020.06.18
'''

score = ([80,90,88,75,91,65],[75,65,80,92],[90,90,88,95,70],[83,77,89,65,99])
list1, list2, list3, list4 = score
sum1,sum2,sum3,sum4 = 0,0,0,0

for x in list1 :
    sum1 += x
for x in list2 :
    sum2 += x
for x in list3 :
    sum3 += x
for x in list4 :
    sum4 += x
average1 = sum1/len(list1)
average2 = sum2/len(list2)
average3 = sum3/len(list3)
average4 = sum4/len(list4)
print('1반 평균 : %4.2f' % average1)
print('2반 평균 : %4.2f' % average2)
print('3반 평균 : %4.2f' % average3)
print('4반 평균 : %4.2f' % average4)
