n = 1
k = 1
while n <= 4 :
    while k < 5 :
        print('(%d, %d)' % (n,k), end=' ')
        k += 1
    print('(%d, 5)' % n)
    n += 1
    k = 1
