A = int(input('정수를 입력하세요. : '))
B = int(input('다른 정수를 입력하세요. : '))
if A > B :
    print(str(A)+'이 더 크다.')
else :
    print(str(B)+'이 더 크다.')
C = A % 2
if C == 1 :
    print(str(A)+'은 홀수이다')
else :
    print(str(A)+'은 짝수이다')
D = B % 2
if D == 1 :
    print(str(B)+'은 홀수이다')
else :
    print(str(B)+'은 짝수이다')
