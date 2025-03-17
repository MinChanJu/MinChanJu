num = int(input('input data : '))
n = 1

while n <= num :
    if n%2 == 1 :
        n += 1
        continue
    print(n, end=' ')
    n += 1
