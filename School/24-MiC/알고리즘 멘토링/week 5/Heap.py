import heapq

print("---------------------------------")
print("Heap - 삽입 (4)")

A = [3, 5, 8, 6, 13, 36, 29, 19, 10, 17]
print(A)

heapq.heappush(A,4)
print(A)

print("---------------------------------")
print("Heap - 삭제")

A = [3, 5, 8, 6, 13, 36, 29, 19, 10, 17]
print(A)

print(heapq.heappop(A))
print(A)


print("---------------------------------")
print("Min Heap")

A = [5,1,4,2,3]
heapq.heapify(A)
print(A)

print(heapq.heappop(A))
print(A)

heapq.heappush(A,-5)
print(heapq.heappop(A))
print(A)


print("---------------------------------")
print("Max Heap")

A = [5,1,4,2,3]
for i in range(len(A)):
    A[i] *= -1
heapq.heapify(A)
print(A)

print(-heapq.heappop(A))
print(A)

heapq.heappush(A,-100)
print(-heapq.heappop(A))
print(A)