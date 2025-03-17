import sys
input=sys.stdin.readline

K,N = map(int,input().split())

ls = []
for i in range(K):
    ls.append(int(input()))

s = 0
e = sum(ls)//N
ls.sort()

while s <= e:
    mid = (s+e)//2
    SUM = 0
    if mid == 0:
        break
    for i in ls:
        SUM += i//mid
    if SUM >= N:
        s = mid+1
    elif SUM < N:
        e = mid-1

print(e)