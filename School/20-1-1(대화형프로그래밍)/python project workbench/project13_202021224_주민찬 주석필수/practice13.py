num = 1
total = 0

from random import randint

print('번호\t성적')
print('====================')
while num <= 30 :
    score = randint(0, 100)
    total += score
    print('%d\t%d' % (num, score))
    num += 1
print('====================')
print('총점\t%d' % total)
print('평균\t%4.2f' % float(total/30))
