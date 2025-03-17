total = 0
num = 1

while 1 <= num <=100 :
    if num%7 == 0 :
        total += num
        num += 1
    else :
        num += 1
print('1부터 100 사이의 모든 7의 배수의 합은 %d입니다.' %total)
