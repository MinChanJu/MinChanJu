'''
project #30 고객평가에 따른 제품 판단 프로그램

Author        : 주민찬
ID number     : 202021224
Details       : 우수제품과 판매중지 제품을 고객평가에 따라 출력하는 프롤그램
Input         : X
Output        : 우수제품, 판매중지, 판매중지 제품에 로션의 존재여부
File Name     : practice30.py
History       : 2020.06.24
'''

product = {'비누', '칫솔', '샴푸', '치약', '로션'}
sale_over4 = {'칫솔', '치약', '로션'}
customer_over4 = {'칫솔', '치약'}

superb = sale_over4 & customer_over4
stop = product - (sale_over4 | customer_over4)

print('우수 제품 :', superb)
print('판매중지 제품 :', stop)
if bool('로션' in stop) == True :
    print('로션은 판매중지에 해당됨')
else :
    print('로션은 판매중지에 해당 안 됨')
