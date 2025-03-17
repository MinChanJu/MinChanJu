num = int(input('0이 아닌 정수 입력 : '))
# 양의 정수 입력시 항상 양수로 나와
# 0이 아닌 정수 입력으로 변경
def odd_even(num) :
    if num%2 == 0 :
        print('odd_even()의 결과 : 짝수')
    else :
        print('odd_even()의 결과 : 홀수')
def posi_nega(num) :
    if num > 0 :
        print('posi_nega()의 결과 : 양수')
    else :
        print('posi_nega()의 결과 : 음수')
odd_even(num)
posi_nega(num)
