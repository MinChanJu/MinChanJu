print("a, b를 공백을 사이에 두고 입력해주세요. 현재 진법(a)과 변환할 진법(b)")
a, b = map(int,input().split())
print(f"{a}진법인 수를 입력해주세요.")
n = input()
d = 0

for i in range(len(n)-1,-1,-1):
    d += int(n[i])*a**(len(n)-1-i)

ls = []
while d != 0:
    ls.append(d%b)
    d //= b

ls.reverse()
print(*ls, sep="")