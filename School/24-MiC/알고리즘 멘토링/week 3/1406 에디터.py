import sys
input = sys.stdin.readline

front = list(input().strip())
M=int(input())
back=[]

for _ in range(M):
    a = list(input().split())
    if a[0] == 'P':
        front.append(a[1])
    elif a[0] == 'L':
        if front:
            back.append(front.pop())
    elif a[0] == 'D':
        if back:
            front.append(back.pop())
    elif a[0] == 'B':
        if front:
            x = front.pop()
back.reverse()
print(*front,sep='',end='')
print(*back,sep='')