import sys
input = sys.stdin.readline

mushroom = []
for i in range(10):
    mushroom.append(int(input()))

prefix_sum = [0 for _ in range(11)]
k = 0

for i in range(1,11):
    prefix_sum[i] = prefix_sum[i-1] + mushroom[i-1]
    if abs(prefix_sum[i] - 100) > abs(prefix_sum[i-1] - 100):
        print(prefix_sum[i-1])
        k = 1
        break
    elif abs(prefix_sum[i] - 100) == abs(prefix_sum[i-1] - 100):
        print(prefix_sum[i])
        k = 1
        break

if k == 0:
    print(prefix_sum[-1])