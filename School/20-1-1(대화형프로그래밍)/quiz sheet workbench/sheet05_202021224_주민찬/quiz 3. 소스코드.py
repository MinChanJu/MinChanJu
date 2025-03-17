number = int(input('Inpput Number'))
A = number%2
print('입력한 '+str(number)+'의 2의 배수 검사 결과는 '
      +str(A)+'로', not bool(A), '이다')
